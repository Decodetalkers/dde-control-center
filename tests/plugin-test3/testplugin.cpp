// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#include "testplugin.h"

#include "interface/hlistmodule.h"
#include "interface/moduleobject.h"

// #include "interface/vlistmodule.h"

#include "src/frame/utils.h"
#include "tests/plugin-test3/BackendObject.h"
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

QString Test2Plugin::name() const
{
    return QStringLiteral("plugin-test3");
}

ModuleObject *Test2Plugin::module()
{
    qmlRegisterSingletonType<BackendObject>(
            "Command.Base",
            1,
            0,
            "BackendObject",
            [](QQmlEngine *, QJSEngine *) -> QObject * {
                auto bak = BackendObject::instance();
                QQmlEngine::setObjectOwnership(bak, QQmlEngine::CppOwnership);
                return bak;
            });

    auto topPage = new HListModule(this);
    topPage->setIcon(QIcon::fromTheme("preferences-system"));
    topPage->setDescription("Qml Test");
    topPage->setDisplayName("Qml Test");
    topPage->setName("qmltest");
    auto aboutPcPage = new PageModule(this);
    aboutPcPage->setName("aboutPc");
    aboutPcPage->setDisplayName(tr("About This Pc"));

    auto module = new AboutThisPcModule;
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
    topPage->appendChild(aboutPcPage);
    return topPage;
}

AboutThisPcModule::AboutThisPcModule(QObject *parent)
    : DCC_NAMESPACE::PageModule(parent)
{
}

QWidget *AboutThisPcModule::page()
{
    auto quickwidget = new QQuickWidget;
    quickwidget->setSource(QUrl("qrc:/qml/aboutpc.qml"));

    quickwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickwidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    return quickwidget;
}

void AboutThisPcModule::active()
{
    BackendObject::instance()->active();
}
