#include "core/application.h"

#include <QtQml/qqmlextensionplugin.h>

Q_IMPORT_QML_PLUGIN(QuickWidgetsPlugin)

int main(int argc, char* argv[]) {
  using namespace room_sketcher;
  Application app(argc, argv);
  if (app.qmlEngine()->rootObjects().isEmpty())
    return 1;
  return app.run();
}
