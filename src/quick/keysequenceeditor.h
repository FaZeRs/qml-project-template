#ifndef KEYSEQUENCEEDITOR_H
#define KEYSEQUENCEEDITOR_H

#include <QQuickItem>
#include <QKeySequence>

class QKeyEvent;

class KeySequenceEditor : public QQuickItem
{
    Q_OBJECT
    // The sequence that is current in the settings (e.g. is current when the settings dialog was opened).
    Q_PROPERTY(QString originalSequence READ originalSequence WRITE setOriginalSequence NOTIFY originalSequenceChanged)
    // The last sequence that was successfully entered.
    Q_PROPERTY(QString newSequence READ newSequence NOTIFY newSequenceChanged)
    Q_PROPERTY(QString displaySequence READ displaySequence NOTIFY displaySequenceChanged)
    Q_PROPERTY(bool hasChanged READ hasChanged NOTIFY hasChangedChanged)
    QML_ELEMENT

public:
    KeySequenceEditor();

    QString originalSequence() const;
    void setOriginalSequence(const QString &originalSequence);

    QString newSequence() const;

    QString displaySequence() const;

    bool hasChanged() const;

public slots:
    void reset();

signals:
    void originalSequenceChanged();
    void newSequenceChanged();
    void displaySequenceChanged();
    void hasChangedChanged();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    void setCurrentSequence(const QString &currentSequence);
    void setNewSequence(const QString &newSequence);

    void resetKeysPressed();

    void accept();
    void cancel();
    bool validate(const QKeySequence &sequence) const;

    QKeySequence m_OriginalSequence;
    QKeySequence m_CurrentSequence;
    QKeySequence m_NewSequence;
    int m_CurrentKeyIndex{0};
    QVector<int> m_KeysPressed;
};

#endif // KEYSEQUENCEEDITOR_H