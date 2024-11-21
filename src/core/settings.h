#pragma once

#include <QSettings>
#include <QString>

class QObject;

namespace myproject {

/// @brief The Settings class is a singleton that manages the application
/// settings.
class Settings : public QSettings {
  Q_OBJECT

  Q_PROPERTY(
      QString language READ language WRITE setLanguage NOTIFY languageChanged)
  Q_PROPERTY(qreal windowOpacity READ windowOpacity WRITE setWindowOpacity
                 NOTIFY windowOpacityChanged)
  Q_PROPERTY(bool fpsVisible READ isFpsVisible WRITE setFpsVisible NOTIFY
                 fpsVisibleChanged)
  Q_PROPERTY(
      QString appTheme READ appTheme WRITE setAppTheme NOTIFY appThemeChanged)

  Q_PROPERTY(QString newShortcut READ newShortcut WRITE setNewShortcut NOTIFY
                 newShortcutChanged)
  Q_PROPERTY(QString openShortcut READ openShortcut WRITE setOpenShortcut NOTIFY
                 openShortcutChanged)
  Q_PROPERTY(QString saveShortcut READ saveShortcut WRITE setSaveShortcut NOTIFY
                 saveShortcutChanged)
  Q_PROPERTY(QString saveAsShortcut READ saveAsShortcut WRITE setSaveAsShortcut
                 NOTIFY saveAsShortcutChanged)
  Q_PROPERTY(QString quitShortcut READ quitShortcut WRITE setQuitShortcut NOTIFY
                 quitShortcutChanged)
  Q_PROPERTY(QString undoShortcut READ undoShortcut WRITE setUndoShortcut NOTIFY
                 undoShortcutChanged)
  Q_PROPERTY(QString redoShortcut READ redoShortcut WRITE setRedoShortcut NOTIFY
                 redoShortcutChanged)
  Q_PROPERTY(QString copyShortcut READ copyShortcut WRITE setCopyShortcut NOTIFY
                 copyShortcutChanged)
  Q_PROPERTY(QString cutShortcut READ cutShortcut WRITE setCutShortcut NOTIFY
                 cutShortcutChanged)
  Q_PROPERTY(QString pasteShortcut READ pasteShortcut WRITE setPasteShortcut
                 NOTIFY pasteShortcutChanged)
  Q_PROPERTY(QString optionsShortcut READ optionsShortcut WRITE
                 setOptionsShortcut NOTIFY optionsShortcutChanged)
  Q_PROPERTY(QString fullScreenShortcut READ fullScreenShortcut WRITE
                 setFullScreenShortcut NOTIFY fullScreenShortcutChanged)

 public:
  explicit Settings(QObject *parent = nullptr);
  Settings(const QString &organization, const QString &application,
           QObject *parent = nullptr);

  /// @brief Returns the default language for the application.
  /// @return The default language.
  [[nodiscard]] QString defaultLanguage() const;
  /// @brief Returns the current language for the application.
  /// @return The current language.
  [[nodiscard]] QString language() const;
  /// @brief Sets the current language for the application.
  /// @param language The new language.
  void setLanguage(const QString &language);

  /// @brief Returns the default window opacity for the application.
  /// @return The default window opacity.
  [[nodiscard]] qreal defaultWindowOpacity() const;
  /// @brief Returns the current window opacity for the application.
  /// @return The current window opacity.
  [[nodiscard]] qreal windowOpacity() const;
  /// @brief Sets the current window opacity for the application.
  /// @param opacity The new window opacity.
  void setWindowOpacity(const qreal opacity);

  /// @brief Returns the default FPS visibility for the application.
  /// @return The default FPS visibility.
  [[nodiscard]] bool defaultFpsVisible() const;
  /// @brief Returns the current FPS visibility for the application.
  /// @return The current FPS visibility.
  [[nodiscard]] bool isFpsVisible() const;
  /// @brief Sets the current FPS visibility for the application.
  /// @param fps_visible The new FPS visibility.
  void setFpsVisible(const bool fps_visible);

  /// @brief Returns the default app theme for the application.
  /// @return The default app theme.
  [[nodiscard]] QString defaultAppTheme() const;
  /// @brief Returns the current app theme for the application.
  /// @return The current app theme.
  [[nodiscard]] QString appTheme() const;
  /// @brief Sets the current app theme for the application.
  /// @param theme The new app theme.
  void setAppTheme(const QString &theme);

  /// @brief Resets all shortcuts to their default values.
  Q_INVOKABLE void resetShortcutsToDefaults();

  /// @brief Returns the default new shortcut for the application.
  /// @return The default new shortcut.
  [[nodiscard]] QString defaultNewShortcut() const;
  /// @brief Returns the current new shortcut for the application.
  /// @return The current new shortcut.
  [[nodiscard]] QString newShortcut() const;
  /// @brief Sets the current new shortcut for the application.
  /// @param shortcut The new new shortcut.
  void setNewShortcut(const QString &shortcut);

  /// @brief Returns the default open shortcut for the application.
  /// @return The default open shortcut.
  [[nodiscard]] QString defaultOpenShortcut() const;
  /// @brief Returns the current open shortcut for the application.
  /// @return The current open shortcut.
  [[nodiscard]] QString openShortcut() const;
  /// @brief Sets the current open shortcut for the application.
  /// @param shortcut The new open shortcut.
  void setOpenShortcut(const QString &shortcut);

  /// @brief Returns the default save shortcut for the application.
  /// @return The default save shortcut.
  [[nodiscard]] QString defaultSaveShortcut() const;
  /// @brief Returns the current save shortcut for the application.
  /// @return The current save shortcut.
  [[nodiscard]] QString saveShortcut() const;
  /// @brief Sets the current save shortcut for the application.
  /// @param shortcut The new save shortcut.
  void setSaveShortcut(const QString &shortcut);

  /// @brief Returns the default save as shortcut for the application.
  /// @return The default save as shortcut.
  [[nodiscard]] QString defaultSaveAsShortcut() const;
  /// @brief Returns the current save as shortcut for the application.
  /// @return The current save as shortcut.
  [[nodiscard]] QString saveAsShortcut() const;
  /// @brief Sets the current save as shortcut for the application.
  /// @param shortcut The new save as shortcut.
  void setSaveAsShortcut(const QString &shortcut);

  /// @brief Returns the default quit shortcut for the application.
  /// @return The default quit shortcut.
  [[nodiscard]] QString defaultQuitShortcut() const;
  /// @brief Returns the current quit shortcut for the application.
  /// @return The current quit shortcut.
  [[nodiscard]] QString quitShortcut() const;
  /// @brief Sets the current quit shortcut for the application.
  /// @param shortcut The new quit shortcut.
  void setQuitShortcut(const QString &shortcut);

  /// @brief Returns the default undo shortcut for the application.
  /// @return The default undo shortcut.
  [[nodiscard]] QString defaultUndoShortcut() const;
  /// @brief Returns the current undo shortcut for the application.
  /// @return The current undo shortcut.
  [[nodiscard]] QString undoShortcut() const;
  /// @brief Sets the current undo shortcut for the application.
  /// @param shortcut The new undo shortcut.
  void setUndoShortcut(const QString &shortcut);

  /// @brief Returns the default redo shortcut for the application.
  /// @return The default redo shortcut.
  [[nodiscard]] QString defaultRedoShortcut() const;
  /// @brief Returns the current redo shortcut for the application.
  /// @return The current redo shortcut.
  [[nodiscard]] QString redoShortcut() const;
  /// @brief Sets the current redo shortcut for the application.
  /// @param shortcut The new redo shortcut.
  void setRedoShortcut(const QString &shortcut);

  /// @brief Returns the default copy shortcut for the application.
  /// @return The default copy shortcut.
  [[nodiscard]] QString defaultCopyShortcut() const;
  /// @brief Returns the current copy shortcut for the application.
  /// @return The current copy shortcut.
  [[nodiscard]] QString copyShortcut() const;
  /// @brief Sets the current copy shortcut for the application.
  /// @param shortcut The new copy shortcut.
  void setCopyShortcut(const QString &shortcut);

  /// @brief Returns the default cut shortcut for the application.
  /// @return The default cut shortcut.
  [[nodiscard]] QString defaultCutShortcut() const;
  /// @brief Returns the current cut shortcut for the application.
  /// @return The current cut shortcut.
  [[nodiscard]] QString cutShortcut() const;
  /// @brief Sets the current cut shortcut for the application.
  /// @param shortcut The new cut shortcut.
  void setCutShortcut(const QString &shortcut);

  /// @brief Returns the default paste shortcut for the application.
  /// @return The default paste shortcut.
  [[nodiscard]] QString defaultPasteShortcut() const;
  /// @brief Returns the current paste shortcut for the application.
  /// @return The current paste shortcut.
  [[nodiscard]] QString pasteShortcut() const;
  /// @brief Sets the current paste shortcut for the application.
  /// @param shortcut The new paste shortcut.
  void setPasteShortcut(const QString &shortcut);

  /// @brief Returns the default options shortcut for the application.
  /// @return The default options shortcut.
  [[nodiscard]] QString defaultOptionsShortcut() const;
  /// @brief Returns the current options shortcut for the application.
  /// @return The current options shortcut.
  [[nodiscard]] QString optionsShortcut() const;
  /// @brief Sets the current options shortcut for the application.
  /// @param shortcut The new options shortcut.
  void setOptionsShortcut(const QString &shortcut);

  /// @brief Returns the default full screen shortcut for the application.
  /// @return The default full screen shortcut.
  [[nodiscard]] QString defaultFullScreenShortcut() const;
  /// @brief Returns the current full screen shortcut for the application.
  /// @return The current full screen shortcut.
  [[nodiscard]] QString fullScreenShortcut() const;
  /// @brief Sets the current full screen shortcut for the application.
  /// @param shortcut The new full screen shortcut.
  void setFullScreenShortcut(const QString &shortcut);

 signals:
  /// @brief Emitted when the language is changed.
  void languageChanged();
  /// @brief Emitted when the window opacity is changed.
  void windowOpacityChanged();
  /// @brief Emitted when the FPS visibility is changed.
  void fpsVisibleChanged();
  /// @brief Emitted when the app theme is changed.
  void appThemeChanged();

  /// @brief Emitted when the new shortcut is changed.
  void newShortcutChanged();
  /// @brief Emitted when the open shortcut is changed.
  void openShortcutChanged();
  /// @brief Emitted when the save shortcut is changed.
  void saveShortcutChanged();
  /// @brief Emitted when the save as shortcut is changed.
  void saveAsShortcutChanged();
  /// @brief Emitted when the quit shortcut is changed.
  void quitShortcutChanged();

  /// @brief Emitted when the undo shortcut is changed.
  void undoShortcutChanged();
  /// @brief Emitted when the redo shortcut is changed.
  void redoShortcutChanged();
  /// @brief Emitted when the copy shortcut is changed.
  void copyShortcutChanged();
  /// @brief Emitted when the cut shortcut is changed.
  void cutShortcutChanged();
  /// @brief Emitted when the paste shortcut is changed.
  void pasteShortcutChanged();

  /// @brief Emitted when the options shortcut is changed.
  void optionsShortcutChanged();
  /// @brief Emitted when the full screen shortcut is changed.
  void fullScreenShortcutChanged();
};

}  // namespace myproject
