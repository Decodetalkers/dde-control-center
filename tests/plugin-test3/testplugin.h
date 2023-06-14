// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "interface/moduleobject.h"
#include "interface/pagemodule.h"
#include "interface/plugininterface.h"

class Test2Plugin : public DCC_NAMESPACE::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.deepin.dde.ControlCenter.test3" FILE "plugin-test.json")
    Q_INTERFACES(DCC_NAMESPACE::PluginInterface)

public:
    virtual QString name() const override;
    virtual DCC_NAMESPACE::ModuleObject *module() override;

signals:
    void updateAll();
};

class QQuickPageModule : public dccV23::ModuleObject
{
    Q_OBJECT
public:
    explicit QQuickPageModule(QObject *parent = nullptr);

    QWidget *page() override;

    void active() override;
};
