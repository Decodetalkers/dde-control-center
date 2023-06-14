#include "LicencesBackendObject.h"

#include <DSysInfo>

#include <QFile>
using Dtk::Core::DSysInfo;
#define IS_COMMUNITY_SYSTEM (DSysInfo::UosCommunity == DSysInfo::uosEditionType()) // 是否是社区版
static LicenseBackendObject *BACKEND = nullptr;

inline QString get_private_title()
{
    return QObject::tr("Privacy Policy");
}

inline static const QStringList SYSTEM_LOCAL_LIST{
    "zh_CN",
    "zh_HK",
    "zh_TW",
    "ug_CN", // 维语
    "bo_CN"  // 藏语
};

inline bool isFileExist(const QString &path)
{
    QFile file(path);
    return file.exists();
}

static const QString getLicensePath(const QString &filePath, const QString &type)
{
    const QString &locale{ QLocale::system().name() };
    QString lang = SYSTEM_LOCAL_LIST.contains(locale) ? locale : "en_US";

    QString path = QString(filePath).arg(lang).arg(type);
    if (isFileExist(path))
        return path;
    else
        return QString(filePath).arg("en_US").arg(type);
}

inline const QString getLicenseText(const QString &filePath, const QString &type)
{
    QFile license(getLicensePath(filePath, type));
    if (!license.open(QIODevice::ReadOnly))
        return QString();

    const QByteArray buf = license.readAll();
    license.close();

    return buf;
}

inline std::pair<QString, QString> loadLicenses()
{
    const QString title = getLicenseText(":/systeminfo/gpl/gpl-3.0-%1-%2.txt", "title");
    const QString body = getLicenseText(":/systeminfo/gpl/gpl-3.0-%1-%2.txt", "body");
    return { title, body };
}

inline QString get_private_text()
{
    QString http = IS_COMMUNITY_SYSTEM
            ? QObject::tr("https://www.deepin.org/en/agreement/privacy/")
            : QObject::tr("https://www.uniontech.com/agreement/privacy-en");
    return QObject::tr("<p>We are deeply aware of the importance of your personal information to "
                       "you. So we have the Privacy Policy that covers how we collect, use, share, "
                       "transfer, publicly disclose, and store your information.</p>"
                       "<p>You can <a href=\"%1\">click here</a> to view our latest privacy policy "
                       "and/or view it online by visiting <a href=\"%1\"> %1</a>. Please read "
                       "carefully and fully understand our practices on customer privacy. If you "
                       "have any questions, please contact us at: support@uniontech.com.</p>")
            .arg(http);
}

LicenseBackendObject *LicenseBackendObject::instance()
{
    if (!BACKEND) {
        BACKEND = new LicenseBackendObject;
    }
    return BACKEND;
}

LicenseBackendObject::LicenseBackendObject(QObject *parent)
    : QObject(parent)
    , m_privateLicense(get_private_text())
    , m_privateLicenseTitle(get_private_title())
{
}

void LicenseBackendObject::active()
{
    if (m_gnuLicenseTitle.has_value() && m_gnuLicense.has_value()) {
        return;
    }
    auto [title, context] = loadLicenses();
    m_gnuLicenseTitle = title;
    m_gnuLicense = context;
    Q_EMIT gnuLicenseChanged();
    Q_EMIT gnuLicenseTitleChanged();
}
