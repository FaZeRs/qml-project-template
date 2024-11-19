#include <settings.h>

#include <QSignalSpy>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test default values", "[Settings]") {
  myproject::Settings settings;
  REQUIRE(settings.defaultLanguage() == "en_GB");
  REQUIRE(settings.defaultWindowOpacity() == 1.0);
  REQUIRE(settings.defaultFpsVisible() == false);
  REQUIRE(settings.defaultQuitShortcut() == "Ctrl+Q");
  REQUIRE(settings.defaultOptionsShortcut() == "Ctrl+,");
  REQUIRE(settings.defaultFullScreenShortcut() == "Ctrl+F");
}

TEST_CASE("Test language", "[Settings]") {
  myproject::Settings settings;
  settings.setLanguage(QString("fr"));
  REQUIRE(settings.language() == QString("fr"));
  QSignalSpy spy(&settings, &myproject::Settings::languageChanged);
  settings.setLanguage(QString("de"));
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.language() == QString("de"));
}

TEST_CASE("Test window opacity", "[Settings]") {
  myproject::Settings settings;
  settings.setWindowOpacity(0.8);
  REQUIRE(settings.windowOpacity() == 0.8);
  QSignalSpy spy(&settings, &myproject::Settings::windowOpacityChanged);
  settings.setWindowOpacity(0.5);
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.windowOpacity() == 0.5);
}

TEST_CASE("Test fps visible", "[Settings]") {
  myproject::Settings settings;
  settings.setFpsVisible(true);
  REQUIRE(settings.isFpsVisible() == true);
  QSignalSpy spy(&settings, &myproject::Settings::fpsVisibleChanged);
  settings.setFpsVisible(false);
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.isFpsVisible() == false);
}

TEST_CASE("Test quit shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setQuitShortcut("Ctrl+X");
  REQUIRE(settings.quitShortcut() == "Ctrl+X");
  QSignalSpy spy(&settings, &myproject::Settings::quitShortcutChanged);
  settings.setQuitShortcut("Ctrl+Q");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.quitShortcut() == "Ctrl+Q");
}

TEST_CASE("Test options shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setOptionsShortcut("Ctrl+P");
  REQUIRE(settings.optionsShortcut() == "Ctrl+P");
  QSignalSpy spy(&settings, &myproject::Settings::optionsShortcutChanged);
  settings.setOptionsShortcut("Ctrl+O");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.optionsShortcut() == "Ctrl+O");
}

TEST_CASE("Test full screen shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setFullScreenShortcut("Ctrl+G");
  REQUIRE(settings.fullScreenShortcut() == "Ctrl+G");
  QSignalSpy spy(&settings, &myproject::Settings::fullScreenShortcutChanged);
  settings.setFullScreenShortcut("Ctrl+F");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.fullScreenShortcut() == "Ctrl+F");
}

TEST_CASE("Test reset shortcuts to defaults", "[Settings]") {
  myproject::Settings settings;
  settings.setQuitShortcut("Ctrl+X");
  settings.setOptionsShortcut("Ctrl+P");
  settings.setFullScreenShortcut("Ctrl+G");
  settings.resetShortcutsToDefaults();
  REQUIRE(settings.quitShortcut() == settings.defaultQuitShortcut());
  REQUIRE(settings.optionsShortcut() == settings.defaultOptionsShortcut());
  REQUIRE(settings.fullScreenShortcut() ==
          settings.defaultFullScreenShortcut());
}
