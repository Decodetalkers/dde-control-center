// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#include "testplugin.h"

#include "interface/hlistmodule.h"
#include "interface/moduleobject.h"

// #include "interface/vlistmodule.h"

#include "AboutMyPcBackendObject.h"
#include "LicencesBackendObject.h"
#include "interface/vlistmodule.h"
#include "widgets/itemmodule.h"

#include <interface/pagemodule.h>
#include <qboxlayout.h>

#include <DGuiApplicationHelper>
#include <DSysInfo>

#include <QApplication>
#include <QLabel>
#include <QPalette>
#include <QQmlEngine>
#include <QQuickWidget>
#include <QSettings>
using Dtk::Core::DSysInfo;

using namespace DCC_NAMESPACE;

#define IS_COMMUNITY_SYSTEM (DSysInfo::UosCommunity == DSysInfo::uosEditionType()) // 是否是社区版

static const QString systemCopyright()
{
    const QSettings settings("/etc/deepin-installer.conf", QSettings::IniFormat);
    const QString &oem_copyright = settings.value("system_info_vendor_name").toString().toLatin1();
    if (oem_copyright.isEmpty()) {
        if (IS_COMMUNITY_SYSTEM)
            return QApplication::translate("LogoModule", "Copyright© 2011-%1 Deepin Community")
                    .arg(QString(__DATE__).right(4));
        else
            return QApplication::translate(
                           "LogoModule",
                           "Copyright© 2019-%1 UnionTech Software Technology Co., LTD")
                    .arg(QString(__DATE__).right(4));
    } else {
        return oem_copyright;
    }
}

void registerGlobalObjects()
{
    qmlRegisterSingletonType<AboutMyPcBackendObject>(
            "Command.Base",
            1,
            0,
            "AboutMyPc",
            [](QQmlEngine *, QJSEngine *) -> QObject * {
                auto bak = AboutMyPcBackendObject::instance();
                QQmlEngine::setObjectOwnership(bak, QQmlEngine::CppOwnership);
                return bak;
            });
    qmlRegisterSingletonType<AboutMyPcBackendObject>(
            "Command.Base",
            1,
            0,
            "LicenseObject",
            [](QQmlEngine *, QJSEngine *) -> QObject * {
                auto bak = LicenseBackendObject::instance();
                QQmlEngine::setObjectOwnership(bak, QQmlEngine::CppOwnership);
                return bak;
            });
}

QString Test2Plugin::name() const
{
    return QStringLiteral("plugin-test3");
}

ModuleObject *Test2Plugin::aboutPcModule()
{
    auto aboutPcPage = new PageModule(this);
    aboutPcPage->setName("aboutPc");
    aboutPcPage->setDisplayName(tr("About This Pc"));

    auto module = new AboutMyPcModule;
    auto bottom = new ItemModule(
            "",
            "",
            [](ModuleObject *) {
                QWidget *logo = new QWidget;
                QHBoxLayout *layout = new QHBoxLayout(logo);
                QLabel *logolabel = new QLabel;
                logolabel->setPixmap(
                        QIcon::fromTheme(DSysInfo::distributionOrgLogo(DSysInfo::Distribution,
                                                                       DSysInfo::Normal))
                                .pixmap(100, 20));
                QLabel *textlabel = new QLabel(systemCopyright());
                layout->addStretch();
                layout->addWidget(logolabel);
                layout->addWidget(textlabel);
                layout->addStretch();

                return logo;
            },
            false);
    bottom->setExtra(true);
    aboutPcPage->appendChild(module);
    aboutPcPage->appendChild(bottom);
    return aboutPcPage;
}

ModuleObject *Test2Plugin::licenseModule()
{
    VListModule *licenseModule = new VListModule(this);
    licenseModule->setName("agreement");
    licenseModule->setDisplayName(tr("Agreements and PrivacyPolicy"));
    auto gnulicense = new LicenseBaseModule(QUrl("qrc:/qml/gnulicense.qml"));
    gnulicense->setIcon(QIcon::fromTheme("dcc_version"));
    gnulicense->setName("editionLicense");
    gnulicense->setDisplayName(tr("Edition License"));
    licenseModule->appendChild(gnulicense);
    return licenseModule;
}

ModuleObject *Test2Plugin::module()
{
    registerGlobalObjects();
    auto topPage = new HListModule(this);
    topPage->setIcon(QIcon::fromTheme("preferences-system"));
    topPage->setDescription("Qml Test");
    topPage->setDisplayName("Qml Test");
    topPage->setName("qmltest");
    topPage->appendChild(aboutPcModule());
    topPage->appendChild(licenseModule());
    return topPage;
}

QQuickPageModule::QQuickPageModule(QUrl rootRes, QObject *parent)
    : DCC_NAMESPACE::PageModule(parent)
    , m_qmlUrl(rootRes)
{
}

QWidget *QQuickPageModule::page()
{
    auto quickwidget = new QQuickWidget;
    quickwidget->setSource(m_qmlUrl);

    quickwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickwidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    return quickwidget;
}

AboutMyPcModule::AboutMyPcModule(QObject *object)
    : QQuickPageModule(QUrl("qrc:/qml/aboutpc.qml"), object)
{
}

void AboutMyPcModule::active()
{

    AboutMyPcBackendObject::instance()->active();
}

LicenseBaseModule::LicenseBaseModule(QUrl rootRes, QObject *parent)
    : QQuickPageModule(rootRes, parent)
{
}

void LicenseBaseModule::active()
{
    LicenseBackendObject::instance()->active();
}
