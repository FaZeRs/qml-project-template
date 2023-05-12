#ifndef ROOM_SKETCHER_SETTINGS_H
#define ROOM_SKETCHER_SETTINGS_H

#include <QSettings>

namespace room_sketcher {

class Settings : public QSettings
{
 public:
  explicit Settings(QObject *parent = nullptr);
};

} // namespace room_sketcher

#endif  // ROOM_SKETCHER_SETTINGS_H
