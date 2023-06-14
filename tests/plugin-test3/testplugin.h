// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "interface/moduleobject.h"
#include "interface/pagemodule.h"
#include "interface/plugininterface.h"

#include <QUrl>

namespace DCC_NAMESPACE {
class Test2Plugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.deepin.dde.ControlCenter.test3" FILE "plugin-test.json")
    Q_INTERFACES(DCC_NAMESPACE::PluginInterface)

public:
    virtual QString name() const override;
    virtual ModuleObject *module() override;

private:
    ModuleObject *aboutPcModule();
    ModuleObject *licenseModule();
};

class QQuickPageModule : public PageModule
{
    Q_OBJECT
public:
    explicit QQuickPageModule(QUrl rootRes, QObject *parent = nullptr);

    QWidget *page() override;

private:
    QUrl m_qmlUrl;
};

class AboutMyPcModule : public QQuickPageModule
{
    Q_OBJECT
public:
    explicit AboutMyPcModule(QObject *parent = nullptr);

    void active() override;
};


class LicenseBaseModule : public QQuickPageModule
{
    Q_OBJECT
public:
    explicit LicenseBaseModule(QUrl rootRes, QObject *parent = nullptr);
    void active() override;
};
} // namespace DCC_NAMESPACE
