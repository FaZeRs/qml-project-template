#include "core/application.h"

int main(int argc, char* argv[]) {
  using namespace room_sketcher;
  Application app(argc, argv);
  if (app.qmlEngine()->rootObjects().isEmpty())
    return 1;
  return app.run();
}
