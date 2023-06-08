// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#include "testplugin.h"

#include "interface/moduleobject.h"
#include "tests/plugin-test3/BackendObject.h"

#include <interface/pagemodule.h>
#include <qqmllist.h>

#include <DGuiApplicationHelper>

#include <QLabel>
#include <QPalette>
#include <QQmlEngine>
#include <QQuickWidget>

using namespace DCC_NAMESPACE;

QString Test2Plugin::name() const
{
    return QStringLiteral("plugin-test3");
}

ModuleObject *Test2Plugin::module()
{
    return new QQuickPageModule;
}

QQuickPageModule::QQuickPageModule(QObject *parent)
    : DCC_NAMESPACE::PageModule(parent)
{
    this->setIcon(QIcon::fromTheme("preferences-system"));
    this->setDescription("Qml Test");
    this->setDisplayName("Qml Test");
    this->setName("qmltest");
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
}

QWidget *QQuickPageModule::page()
{
    auto quickwidget = new QQuickWidget;
    quickwidget->setSource(QUrl("qrc:/qml/main.qml"));
    quickwidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    quickwidget->setClearColor(Qt::transparent);

    quickwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    return quickwidget;
}

void QQuickPageModule::active()
{
    BackendObject::instance()->active();
}
