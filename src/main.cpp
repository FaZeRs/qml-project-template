#include <QtQml/qqmlextensionplugin.h>

#include "core/application.h"

int main(int argc, char* argv[]) {
  using namespace myproject;
  Application app(argc, argv);
  if (app.qmlEngine()->rootObjects().isEmpty()) return 1;
  return app.run();
}
