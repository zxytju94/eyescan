#ifndef SCANPLOT_H
#define SCANPLOT_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSvgWidget>
#include <QComboBox>
#include "ltdhwscan.h"

class QLabel;
class QComboBox;
class QToolButton;
class QHBoxLayout;
class QGridLayout;
class QVBoxLayout;
class LTDHWScan;
class LTDHWScanReader;

class ScanPlot : public QWidget
{
    Q_OBJECT

public:
    ScanPlot(QWidget *parent = 0);
    ~ScanPlot();

    typedef enum
    {
        SVG_CONTOUR_FILLED,
        SVG_CONTOUR_NOFILL,
        SVG_BATHTUB,
        SVG_HEATMAP,
    }SVG_Types;


private slots:
    void svgChange(int);

private:
    void createButtons();
    void createInfos();
    void createInfos1();

    LTDHWScan* scan;
    LTDHWScanReader* reader;

    QSvgWidget* svgWidget;
    QToolButton* backButton;
    QToolButton* forwardButton;
    QToolButton* zoomInButton;
    QToolButton* zoomOutButton;
    QToolButton* fitScreenButton;
    QToolButton* refreshButton;
    QToolButton* openButton;
    QToolButton* helpButton;
    QComboBox* svgType;

    QHBoxLayout* toolBarLayout;
    QGridLayout* attrLayout;
    QVBoxLayout* mainLayout;

};

#endif // SCANPLOT_H
