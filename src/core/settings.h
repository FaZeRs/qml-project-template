#pragma once

#include <QSettings>
#include <QString>

class QObject;

namespace room_sketcher {

class Settings : public QSettings {
  Q_OBJECT

  Q_PROPERTY(
      QString language READ language WRITE setLanguage NOTIFY languageChanged)
  Q_PROPERTY(qreal windowOpacity READ windowOpacity WRITE setWindowOpacity
                 NOTIFY windowOpacityChanged)
  Q_PROPERTY(bool fpsVisible READ isFpsVisible WRITE setFpsVisible NOTIFY
                 fpsVisibleChanged)

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

  /// @brief Resets all shortcuts to their default values.
  Q_INVOKABLE void resetShortcutsToDefaults();

  [[nodiscard]] QString defaultNewShortcut() const;
  [[nodiscard]] QString newShortcut() const;
  void setNewShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultOpenShortcut() const;
  [[nodiscard]] QString openShortcut() const;
  void setOpenShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultSaveShortcut() const;
  [[nodiscard]] QString saveShortcut() const;
  void setSaveShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultSaveAsShortcut() const;
  [[nodiscard]] QString saveAsShortcut() const;
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

  [[nodiscard]] QString defaultUndoShortcut() const;
  [[nodiscard]] QString undoShortcut() const;
  void setUndoShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultRedoShortcut() const;
  [[nodiscard]] QString redoShortcut() const;
  void setRedoShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultCopyShortcut() const;
  [[nodiscard]] QString copyShortcut() const;
  void setCopyShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultCutShortcut() const;
  [[nodiscard]] QString cutShortcut() const;
  void setCutShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultPasteShortcut() const;
  [[nodiscard]] QString pasteShortcut() const;
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

  void newShortcutChanged();
  void openShortcutChanged();
  void saveShortcutChanged();
  void saveAsShortcutChanged();
  /// @brief Emitted when the quit shortcut is changed.
  void quitShortcutChanged();

  void undoShortcutChanged();
  void redoShortcutChanged();
  void copyShortcutChanged();
  void cutShortcutChanged();
  void pasteShortcutChanged();

  /// @brief Emitted when the options shortcut is changed.
  void optionsShortcutChanged();
  /// @brief Emitted when the full screen shortcut is changed.
  void fullScreenShortcutChanged();
};

}  // namespace room_sketcher
