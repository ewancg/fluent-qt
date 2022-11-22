#ifndef CONTROL_H
#define CONTROL_H

#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QVariant>
#include <QWidget>
#include <QtDebug>
#include <QtMath>
#define epx(a) qCeil((a * logicalDpiX()) / 96)
#define mg(a) QMargins(a, a, a, a)

class Control : public QWidget {
  Q_OBJECT
 public:
  explicit Control(QWidget *parent = nullptr);
  QHash<QString, QBrush> *brushes;

  QVariantAnimation foregroundAnimation, backgroundAnimation;
  QBrush foregroundBrush = Qt::transparent, backgroundBrush = Qt::transparent,
         borderBrush = Qt::transparent;
 signals:

 public slots:
  void setText(const QString &text) {
    m_text = text;
    update();
  }
  const QString text() { return m_text; }

  void setTextAlignment(const Qt::Alignment alignment) {
    m_alignment = alignment;
    update();
  }
  const Qt::Alignment textAlignment() { return m_alignment; }

  void setPadding(const QMargins &padding) {
    m_padding = padding;
    update();
  }
  const QMargins padding() { return m_padding; }

  void setFont(const QFont &font) {
    m_font = font;
    update();
  }
  const QFont font() { return m_font; }

 protected:
  QString m_text;
  QMargins m_padding;
  QFont m_font;

  Qt::Alignment m_alignment = Qt::AlignHCenter | Qt::AlignVCenter;

  void paintBackground(QPaintEvent *, QPainter &);
  void paintText(QPaintEvent *, QPainter &);
  void paintEvent(QPaintEvent *event) override;
};

#endif  // CONTROL_H
