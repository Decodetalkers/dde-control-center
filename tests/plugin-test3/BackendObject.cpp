#include "BackendObject.h"

BackendObject::BackendObject(QObject *parent)
    : QObject(parent)
    , m_name("First")
    , m_isGangdum(true)
{
}
