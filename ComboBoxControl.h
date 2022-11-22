#ifndef COMBOBOXCONTROL_H
#define COMBOBOXCONTROL_H

#include <QObject>
#include <QWidget>

#include "ButtonControl.h"

class ComboBoxControl : public ButtonControl {
 public:
  explicit ComboBoxControl(QWidget *parent = nullptr);

  void setGlyph(const QChar &glyph) {
    m_glyph = glyph;
    update();
  }
  const QChar glyph() { return m_glyph; }

 protected:
  QChar m_glyph;
  void paintChevron(QPaintEvent *, QPainter &);
  void paintEvent(QPaintEvent *event) override;
};

#endif  // COMBOBOXCONTROL_H
