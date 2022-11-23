#ifndef CONTROL_H
#define CONTROL_H

#include <QLayout>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QVariant>
#include <QWidget>
#include <QtDebug>
#include <QtMath>
#define epx(a) ((a * this->logicalDpiX()) / 96)
#define mg(a) QMargins(a, a, a, a)

#include <BorderRadius.h>

class Control : public QWidget {
  Q_OBJECT
 public:
  explicit Control(QWidget *parent = nullptr);
  QHash<QString, QBrush> *brushes;

  QVariantAnimation foregroundAnimation, backgroundAnimation;
  QBrush foregroundBrush = Qt::transparent,
         m_background_brush = Qt::transparent, m_border_brush = Qt::transparent;
 signals:

 public slots:
  void setText(const QString &text) {
    m_text = text;
    m_minimum_size = QSize(-1, -1);
    update();
  }
  const QString text() { return m_text; }

  void setTextAlignment(const Qt::Alignment alignment) {
    m_alignment = alignment;
    m_minimum_size = QSize(-1, -1);
    update();
  }
  const Qt::Alignment textAlignment() { return m_alignment; }

  void setPadding(const QMargins &padding) {
    m_padding = padding;
    m_minimum_size = QSize(-1, -1);
    update();
  }
  const QMargins padding() { return m_padding; }

  void setFont(const QFont &font) {
    QWidget::setFont(font);
    m_minimum_size = QSize(-1, -1);
    update();
  }

  void setBorderThickness(int thickness) {
    m_border_thickness = thickness;
    m_minimum_size = QSize(-1, -1);
    m_border_inner_radius.invalidate();
    update();
  }
  int borderThickness() { return m_border_thickness; }

  void setBorderRadius(BorderRadius radius) {
    m_border_radius = radius;
    m_minimum_size = QSize(-1, -1);
    m_border_outer_radius.invalidate();
    m_border_inner_radius.invalidate();
    update();
  }
  BorderRadius borderRadius() { return m_border_radius; }

 public:  // Non-slot overloads
  template <Numeric T>
  void setBorderRadius(T topLeft, T topRight, T bottomLeft, T bottomRight) {
    setBorderRadius(BorderRadius(topLeft, topRight, bottomLeft, bottomRight));
  }
  template <Numeric T>
  void setBorderRadius(T top, T bottom) {
    setBorderRadius(top, top, bottom, bottom);
  }
  template <Numeric T>
  void setBorderRadius(T radius) {
    setBorderRadius(radius, radius, radius, radius);
  }

 protected:
  QString m_text;
  QMargins m_padding;

  QSize m_minimum_size;

  int m_border_thickness = 1;

  BorderRadius
      // Unscaled
      m_border_radius = BorderRadius(4),
      // Scaled; outer raidius - thickness
      m_border_inner_radius = BorderRadius::invalid(),
      // Scaled; unscaled radius * epx
      m_border_outer_radius = BorderRadius::invalid();

  Qt::Alignment m_alignment = Qt::AlignHCenter | Qt::AlignVCenter;

  void evaluateMinimumSize(QPaintEvent *, QPainter &);
  void paintBackground(QPaintEvent *, QPainter &);
  void paintText(QPaintEvent *, QPainter &);
  void paintEvent(QPaintEvent *event) override;
};

#endif  // CONTROL_H
