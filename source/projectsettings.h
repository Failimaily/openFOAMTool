#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H
#include "Singleton.h"
#include <QString>
#define g_pprojectsettings projectSettings::Get()
/*!
 * projectSettings is a singleton. It contains all global program settings.
 * At the moment only contains the model name for glWidget
 */
class projectSettings : public TSingleton<projectSettings>
{
public:
    projectSettings();
    void Init();
    QString modelName;
};

#endif // PROJECTSETTINGS_H
