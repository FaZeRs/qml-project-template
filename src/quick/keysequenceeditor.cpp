#include "keysequenceeditor.h"

#include <spdlog/spdlog.h>

#include <QKeyEvent>
#include <QLoggingCategory>
#include <QMetaEnum>

KeySequenceEditor::KeySequenceEditor() {
    m_KeysPressed.fill(0, 4);
}

QString KeySequenceEditor::originalSequence() const
{
    return m_OriginalSequence.toString();
}

void KeySequenceEditor::setOriginalSequence(const QString &originalSequence)
{
    if (originalSequence == m_OriginalSequence.toString())
        return;

    m_OriginalSequence = QKeySequence(originalSequence, QKeySequence::PortableText);
    setCurrentSequence(QString());
    setNewSequence(QString());
    emit originalSequenceChanged();
    // This might not always be the case, I'm just lazy.
    emit hasChangedChanged();
    emit displaySequenceChanged();
}

QString KeySequenceEditor::newSequence() const
{
    return m_NewSequence.toString();
}

QString KeySequenceEditor::displaySequence() const
{
    QKeySequence sequence = hasActiveFocus()
            ? m_CurrentSequence : (!m_NewSequence.isEmpty() ? m_NewSequence : m_OriginalSequence);
    return sequence.toString();
}

void KeySequenceEditor::setNewSequence(const QString &newSequence)
{
    if (newSequence == m_NewSequence.toString())
        return;

    m_NewSequence = QKeySequence(newSequence, QKeySequence::PortableText);
    SPDLOG_DEBUG("Set new sequence to {}", mNewSequence);
    emit newSequenceChanged();
    emit hasChangedChanged();
    emit displaySequenceChanged();
}

void KeySequenceEditor::resetKeysPressed()
{
    SPDLOG_DEBUG("Clearing pressed keys");

    for (int i = 0; i < m_KeysPressed.size(); ++i) {
        m_KeysPressed[i] = 0;
    }

    m_CurrentKeyIndex = 0;
}

bool KeySequenceEditor::hasChanged() const
{
    return !m_NewSequence.isEmpty() && m_NewSequence != m_OriginalSequence;
}

void KeySequenceEditor::reset()
{
    setCurrentSequence(originalSequence());
    setNewSequence(originalSequence());
    resetKeysPressed();
}

void KeySequenceEditor::setCurrentSequence(const QString &currentSequence)
{
    if (currentSequence == m_CurrentSequence.toString())
        return;

    m_CurrentSequence = QKeySequence(currentSequence, QKeySequence::PortableText);
    SPDLOG_DEBUG("Current sequence changed to {}", mCurrentSequence);
    emit hasChangedChanged();
    emit displaySequenceChanged();
}

void KeySequenceEditor::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        setFocus(false);
    } else if (event->key() == Qt::Key_Return) {
        accept();
    } else if (!event->isAutoRepeat()) {
        int modifiers = 0;
        if (event->modifiers().testFlag(Qt::ControlModifier))
            modifiers |= Qt::CTRL;
        if (event->modifiers().testFlag(Qt::ShiftModifier))
            modifiers |= Qt::SHIFT;
        if (event->modifiers().testFlag(Qt::AltModifier))
            modifiers |= Qt::ALT;
        if (event->modifiers().testFlag(Qt::MetaModifier))
            modifiers |= Qt::META;

        if (event->key() >= Qt::Key_Shift && event->key() <= Qt::Key_Meta) {
            SPDLOG_DEBUG("Only modifiers were pressed ({} / {} / {}); ignoring", event->text(), event->key(), QKeySequence(event->key()));
        } else {
            m_KeysPressed[m_CurrentKeyIndex++] = event->key() | modifiers;
            SPDLOG_DEBUG("Adding key {} / {}  {}  with modifiers {} ({}) to pressed keys", event->text(), event->key(), QKeySequence(event->key()), modifiers, QKeySequence(m_KeysPressed[m_CurrentKeyIndex - 1]));

            const QKeySequence sequence(m_KeysPressed.at(0), m_KeysPressed.at(1), m_KeysPressed.at(2), m_KeysPressed.at(3));
            setCurrentSequence(sequence.toString());

            if (m_CurrentKeyIndex == m_KeysPressed.size() - 1) {
                // That was the last key out of four possible keys; end it here.
                accept();
            }
        }
    }

    event->accept();
}

void KeySequenceEditor::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}

void KeySequenceEditor::focusInEvent(QFocusEvent *event)
{
    event->accept();

    // The text displaying the shortcut should be cleared when editing begins.
    emit displaySequenceChanged();
}

void KeySequenceEditor::focusOutEvent(QFocusEvent *event)
{
    event->accept();

    cancel();
}

void KeySequenceEditor::accept()
{
    SPDLOG_DEBUG("Attempting to accept input...");

    // If there hasn't been anything new successfully entered yet, check against
    // the original sequence, otherwise check against the latest successfully entered sequence.
    // Note: hasChanged() assumes that an empty sequence isn't possible; we might want to accunt for this
    // in the future.
    if ((m_CurrentSequence != m_OriginalSequence) || (hasChanged() && m_CurrentSequence != m_NewSequence)) {
        if (validate(m_CurrentSequence)) {
            SPDLOG_DEBUG("Input valid");
            setNewSequence(m_CurrentSequence.toString());
        } else {
            SPDLOG_DEBUG("Input invalid");
            cancel();
        }
    } else {
        SPDLOG_DEBUG("Nothing has changed in the input");
        // Nothing's changed.
    }

    resetKeysPressed();
    setFocus(false);
}

void KeySequenceEditor::cancel()
{
    resetKeysPressed();
    if (!m_CurrentSequence.isEmpty()) {
        setCurrentSequence(QString());
    } else {
        // If the current sequence is empty, setting it to an empty string
        // obviously won't change anything, and it will return early.
        // We need the display sequence to update though, so call it here.
        emit displaySequenceChanged();
    }
}

bool KeySequenceEditor::validate(const QKeySequence& sequence) const
{
    SPDLOG_DEBUG("Validating key sequence {} ...", sequence);

    bool valid = true;

    // do some checks

    return valid;
}