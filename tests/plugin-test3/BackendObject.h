#pragma once

#include <QDebug>
#include <QObject>

class BackendObject final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    Q_PROPERTY(bool isGangdum READ isGangdum WRITE setIsGangdum NOTIFY isGangdumChanged)
public:
    explicit BackendObject(QObject *parent = nullptr);

    inline QString name() const { return m_name; }

    inline void setName(QString name)
    {
        m_name = name;
        Q_EMIT nameChanged();
    }

    inline bool isGangdum() const { return m_isGangdum; }

    inline void setIsGangdum(bool isGangdum)
    {
        m_isGangdum = isGangdum;
        Q_EMIT isGangdumChanged();
    }

signals:
    void nameChanged();
    void isGangdumChanged();

private:
    QString m_name;
    bool m_isGangdum;
};
