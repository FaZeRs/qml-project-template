#include "settings.h"

#include <QKeySequence>
#include <QLatin1String>
#include <QObject>
#include <QVariant>
#include <QVector>

namespace myproject {

Settings::Settings(QObject *parent) : QSettings(parent) {}

Settings::Settings(const QString &organization, const QString &application,
                   QObject *parent)
    : QSettings(organization, application, parent) {}

QString Settings::defaultLanguage() const { return "en_GB"; }

QString Settings::language() const {
  return value("language", defaultLanguage()).toString();
}

void Settings::setLanguage(const QString &language) {
  if (language == value("language", defaultLanguage()).toString()) return;

  setValue("language", language);
  emit languageChanged();
}

qreal Settings::defaultWindowOpacity() const { return 1.0; }

qreal Settings::windowOpacity() const {
  return value("windowOpacity", defaultWindowOpacity()).toReal();
}

void Settings::setWindowOpacity(const qreal opacity) {
  if (windowOpacity() == opacity) return;

  setValue("windowOpacity", opacity);
  emit windowOpacityChanged();
}

bool Settings::defaultFpsVisible() const { return false; }

bool Settings::isFpsVisible() const {
  return value("fpsVisible", defaultFpsVisible()).toBool();
}

void Settings::setFpsVisible(const bool fps_visible) {
  if (fps_visible == value("fpsVisible", defaultFpsVisible()).toBool()) return;

  setValue("fpsVisible", fps_visible);
  emit fpsVisibleChanged();
}

void Settings::resetShortcutsToDefaults() {
  static const QVector<QString> all_shortcuts = {
      QLatin1String("newShortcut"),     QLatin1String("openShortcut"),
      QLatin1String("saveShortcut"),    QLatin1String("saveAsShortcut"),
      QLatin1String("quitShortcut"),    QLatin1String("undoShortcut"),
      QLatin1String("redoShortcut"),    QLatin1String("copyShortcut"),
      QLatin1String("cutShortcut"),     QLatin1String("pasteShortcut"),
      QLatin1String("optionsShortcut"), QLatin1String("fullScreenShortcut")};
  for (const auto &shortcut : all_shortcuts) {
    remove(shortcut);
  }
}
QString Settings::defaultNewShortcut() const {
  return QKeySequence("Ctrl+N").toString();
}

QString Settings::newShortcut() const {
  return value("newShortcut", defaultNewShortcut()).toString();
}

void Settings::setNewShortcut(const QString &shortcut) {
  if (shortcut == value("newShortcut", defaultNewShortcut()).toString()) {
    return;
  }
  setValue("newShortcut", shortcut);
  emit newShortcutChanged();
}

QString Settings::defaultOpenShortcut() const {
  return QKeySequence("Ctrl+O").toString();
}

QString Settings::openShortcut() const {
  return value("openShortcut", defaultOpenShortcut()).toString();
}

void Settings::setOpenShortcut(const QString &shortcut) {
  if (shortcut == value("openShortcut", defaultOpenShortcut()).toString()) {
    return;
  }
  setValue("openShortcut", shortcut);
  emit openShortcutChanged();
}

QString Settings::defaultSaveShortcut() const {
  return QKeySequence("Ctrl+S").toString();
}

QString Settings::saveShortcut() const {
  return value("saveShortcut", defaultSaveShortcut()).toString();
}

void Settings::setSaveShortcut(const QString &shortcut) {
  if (shortcut == value("saveShortcut", defaultSaveShortcut()).toString()) {
    return;
  }
  setValue("saveShortcut", shortcut);
  emit saveShortcutChanged();
}

QString Settings::defaultSaveAsShortcut() const {
  return QKeySequence("Ctrl+Shift+S").toString();
}

QString Settings::saveAsShortcut() const {
  return value("saveAsShortcut", defaultSaveAsShortcut()).toString();
}

void Settings::setSaveAsShortcut(const QString &shortcut) {
  if (shortcut == value("saveAsShortcut", defaultSaveAsShortcut()).toString()) {
    return;
  }
  setValue("saveAsShortcut", shortcut);
  emit saveAsShortcutChanged();
}

QString Settings::defaultQuitShortcut() const {
  return QKeySequence("Ctrl+Q").toString();
}

QString Settings::quitShortcut() const {
  return value("quitShortcut", defaultQuitShortcut()).toString();
}

void Settings::setQuitShortcut(const QString &shortcut) {
  if (shortcut == value("quitShortcut", defaultQuitShortcut()).toString()) {
    return;
  }
  setValue("quitShortcut", shortcut);
  emit quitShortcutChanged();
}

QString Settings::defaultUndoShortcut() const {
  return QKeySequence("Ctrl+Z").toString();
}

QString Settings::undoShortcut() const {
  return value("undoShortcut", defaultUndoShortcut()).toString();
}

void Settings::setUndoShortcut(const QString &shortcut) {
  if (shortcut == value("undoShortcut", defaultUndoShortcut()).toString()) {
    return;
  }
  setValue("undoShortcut", shortcut);
  emit undoShortcutChanged();
}

QString Settings::defaultRedoShortcut() const {
  return QKeySequence("Ctrl+Y").toString();
}

QString Settings::redoShortcut() const {
  return value("redoShortcut", defaultRedoShortcut()).toString();
}

void Settings::setRedoShortcut(const QString &shortcut) {
  if (shortcut == value("redoShortcut", defaultRedoShortcut()).toString()) {
    return;
  }
  setValue("redoShortcut", shortcut);
  emit redoShortcutChanged();
}

QString Settings::defaultCopyShortcut() const {
  return QKeySequence("Ctrl+C").toString();
}

QString Settings::copyShortcut() const {
  return value("copyShortcut", defaultCopyShortcut()).toString();
}

void Settings::setCopyShortcut(const QString &shortcut) {
  if (shortcut == value("copyShortcut", defaultCopyShortcut()).toString()) {
    return;
  }
  setValue("copyShortcut", shortcut);
  emit copyShortcutChanged();
}

QString Settings::defaultCutShortcut() const {
  return QKeySequence("Ctrl+X").toString();
}

QString Settings::cutShortcut() const {
  return value("cutShortcut", defaultCutShortcut()).toString();
}

void Settings::setCutShortcut(const QString &shortcut) {
  if (shortcut == value("cutShortcut", defaultCutShortcut()).toString()) {
    return;
  }
  setValue("cutShortcut", shortcut);
  emit cutShortcutChanged();
}

QString Settings::defaultPasteShortcut() const {
  return QKeySequence("Ctrl+V").toString();
}

QString Settings::pasteShortcut() const {
  return value("pasteShortcut", defaultPasteShortcut()).toString();
}

void Settings::setPasteShortcut(const QString &shortcut) {
  if (shortcut == value("pasteShortcut", defaultPasteShortcut()).toString()) {
    return;
  }
  setValue("pasteShortcut", shortcut);
  emit pasteShortcutChanged();
}

QString Settings::defaultOptionsShortcut() const {
  return QKeySequence("Ctrl+,").toString();
}

QString Settings::optionsShortcut() const {
  return value("optionsShortcut", defaultOptionsShortcut()).toString();
}

void Settings::setOptionsShortcut(const QString &shortcut) {
  if (shortcut ==
      value("optionsShortcut", defaultOptionsShortcut()).toString()) {
    return;
  }
  setValue("optionsShortcut", shortcut);
  emit optionsShortcutChanged();
}

QString Settings::defaultFullScreenShortcut() const {
  return QKeySequence("Ctrl+F").toString();
}

QString Settings::fullScreenShortcut() const {
  return value("fullScreenShortcut", defaultFullScreenShortcut()).toString();
}

void Settings::setFullScreenShortcut(const QString &shortcut) {
  if (shortcut ==
      value("fullScreenShortcut", defaultFullScreenShortcut()).toString()) {
    return;
  }
  setValue("fullScreenShortcut", shortcut);
  emit fullScreenShortcutChanged();
}

}  // namespace myproject
