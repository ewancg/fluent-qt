#include "mainwindow.h"

#include <windows.h>

#include <QtDebug>
#include <QtMath>

#include "./ui_mainwindow.h"

#pragma comment(lib, "dwmapi.lib")
#include "dwmapi.h"  // only needed for margins. ugh
#include "windows.ui.viewmanagement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_NoSystemBackground, true);
  setAttribute(Qt::WA_OpaquePaintEvent, false);

  Windows::UI::UISettings s;

  auto accent = UISettings().GetColorValue(AccentLight1);

  QTimer::singleShot(0, this, [this] {
    auto hwnd = reinterpret_cast<HWND>(this->winId());

    BOOL dark = true;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark,
                          sizeof(dark));

    MARGINS margins = {-1};
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    auto cycle = [=] {
      static auto param = 1;
      param < 4 ? param++ : param = 1;

      int DWMSBT_MAINWINDOW = param;
      DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &DWMSBT_MAINWINDOW,
                            sizeof(DWMSBT_MAINWINDOW));
    };
    // connect(ui->button, &ButtonControl::released, this, cycle);
    cycle();
  });

  ui->button->setText("Click Me");
  ui->button_3->setProperty("border-thickness", 3);
  ui->button_3->setProperty("border-radius", 12);

  ui->button_3->borderBrush = QColor("#88fc4a88");

  ui->bourt->setProperty("border-radius", 0);

  ui->button_4->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
  ui->button_4->setText("Combo Boxin");
  ui->button_4->setGlyph(QChar('\ue70d'));

  ui->textBlock->setText(
      "zzzzzzzzzzzzzzzzz\nzzzzzzzzzzzzzzzzzzzzzzzzzz\nzzzzzzzzzzzzzzzzzzzzzzzzo"
      "oz");
  connect(ui->button, &ButtonControl::released, this, [this] {
    ui->button->setText("Bazoobledorpf");
    ui->button->update();
  });
}

MainWindow::~MainWindow() { delete ui; }
