#include <settings.h>

#include <QSignalSpy>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test default values", "[Settings]") {
  myproject::Settings settings;
  REQUIRE(settings.defaultLanguage() == "en_GB");
  REQUIRE(settings.defaultWindowOpacity() == 1.0);
  REQUIRE(settings.defaultFpsVisible() == false);
  REQUIRE(settings.defaultNewShortcut() == "Ctrl+N");
  REQUIRE(settings.defaultOpenShortcut() == "Ctrl+O");
  REQUIRE(settings.defaultSaveShortcut() == "Ctrl+S");
  REQUIRE(settings.defaultSaveAsShortcut() == "Ctrl+Shift+S");
  REQUIRE(settings.defaultQuitShortcut() == "Ctrl+Q");
  REQUIRE(settings.defaultUndoShortcut() == "Ctrl+Z");
  REQUIRE(settings.defaultRedoShortcut() == "Ctrl+Y");
  REQUIRE(settings.defaultCopyShortcut() == "Ctrl+C");
  REQUIRE(settings.defaultCutShortcut() == "Ctrl+X");
  REQUIRE(settings.defaultPasteShortcut() == "Ctrl+V");
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

TEST_CASE("Test new shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setNewShortcut("Ctrl+A");
  REQUIRE(settings.newShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::newShortcutChanged);
  settings.setNewShortcut("Ctrl+N");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.newShortcut() == "Ctrl+N");
}

TEST_CASE("Test open shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setOpenShortcut("Ctrl+A");
  REQUIRE(settings.openShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::openShortcutChanged);
  settings.setOpenShortcut("Ctrl+O");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.openShortcut() == "Ctrl+O");
}

TEST_CASE("Test save shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setSaveShortcut("Ctrl+A");
  REQUIRE(settings.saveShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::saveShortcutChanged);
  settings.setSaveShortcut("Ctrl+S");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.saveShortcut() == "Ctrl+S");
}

TEST_CASE("Test save as shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setSaveAsShortcut("Ctrl+A");
  REQUIRE(settings.saveAsShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::saveAsShortcutChanged);
  settings.setSaveAsShortcut("Ctrl+Shift+S");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.saveAsShortcut() == "Ctrl+Shift+S");
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

TEST_CASE("Test undo shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setUndoShortcut("Ctrl+A");
  REQUIRE(settings.undoShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::undoShortcutChanged);
  settings.setUndoShortcut("Ctrl+Z");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.undoShortcut() == "Ctrl+Z");
}

TEST_CASE("Test redo shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setRedoShortcut("Ctrl+A");
  REQUIRE(settings.redoShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::redoShortcutChanged);
  settings.setRedoShortcut("Ctrl+Y");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.redoShortcut() == "Ctrl+Y");
}

TEST_CASE("Test copy shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setCopyShortcut("Ctrl+A");
  REQUIRE(settings.copyShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::copyShortcutChanged);
  settings.setCopyShortcut("Ctrl+C");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.copyShortcut() == "Ctrl+C");
}

TEST_CASE("Test cut shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setCutShortcut("Ctrl+A");
  REQUIRE(settings.cutShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::cutShortcutChanged);
  settings.setCutShortcut("Ctrl+X");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.cutShortcut() == "Ctrl+X");
}

TEST_CASE("Test paste shortcut", "[Settings]") {
  myproject::Settings settings;
  settings.setPasteShortcut("Ctrl+A");
  REQUIRE(settings.pasteShortcut() == "Ctrl+A");
  QSignalSpy spy(&settings, &myproject::Settings::pasteShortcutChanged);
  settings.setPasteShortcut("Ctrl+V");
  REQUIRE(spy.count() == 1);
  REQUIRE(settings.pasteShortcut() == "Ctrl+V");
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
  settings.setNewShortcut("Ctrl+A");
  settings.setOpenShortcut("Ctrl+S");
  settings.setSaveShortcut("Ctrl+D");
  settings.setSaveAsShortcut("Ctrl+F");
  settings.setQuitShortcut("Ctrl+X");
  settings.setUndoShortcut("Ctrl+M");
  settings.setRedoShortcut("Ctrl+N");
  settings.setCopyShortcut("Ctrl+L");
  settings.setCutShortcut("Ctrl+T");
  settings.setPasteShortcut("Ctrl+W");
  settings.setOptionsShortcut("Ctrl+P");
  settings.setFullScreenShortcut("Ctrl+G");
  settings.resetShortcutsToDefaults();
  REQUIRE(settings.newShortcut() == settings.defaultNewShortcut());
  REQUIRE(settings.openShortcut() == settings.defaultOpenShortcut());
  REQUIRE(settings.saveShortcut() == settings.defaultSaveShortcut());
  REQUIRE(settings.saveAsShortcut() == settings.defaultSaveAsShortcut());
  REQUIRE(settings.quitShortcut() == settings.defaultQuitShortcut());
  REQUIRE(settings.undoShortcut() == settings.defaultUndoShortcut());
  REQUIRE(settings.redoShortcut() == settings.defaultRedoShortcut());
  REQUIRE(settings.copyShortcut() == settings.defaultCopyShortcut());
  REQUIRE(settings.cutShortcut() == settings.defaultCutShortcut());
  REQUIRE(settings.pasteShortcut() == settings.defaultPasteShortcut());
  REQUIRE(settings.optionsShortcut() == settings.defaultOptionsShortcut());
  REQUIRE(settings.fullScreenShortcut() ==
          settings.defaultFullScreenShortcut());
}
