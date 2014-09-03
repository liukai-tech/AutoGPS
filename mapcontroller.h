#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H


#include <QObject>
#include <QVariant>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPointer>

QT_BEGIN_NAMESPACE

namespace EsriRuntimeQt
{
class Point;
class MapGraphicsView;
class Map;
class GraphicsLayer;
class Line;
class Envelope;
}
namespace AutoGPSNAMESPACE{
class SimpleGraphicOverlay;
}
QT_END_NAMESPACE
namespace AutoGPSNAMESPACE{
class MapController : public QObject
{
    Q_OBJECT
public:
    explicit MapController(EsriRuntimeQt::Map* inputMap, EsriRuntimeQt::MapGraphicsView *inputGraphicsView, QWidget*);
    ~MapController();
    void setSimpleVisible(bool);
private:
    QPointer<EsriRuntimeQt::Map> map;
    QPointer<EsriRuntimeQt::MapGraphicsView> mapGraphicsView;
    QPointer<QWidget> widget;

    QScopedPointer<EsriRuntimeQt::GraphicsLayer> pointsLayer;
    QScopedPointer<EsriRuntimeQt::Point> ownshipStartingMapPoint;
    QScopedPointer<EsriRuntimeQt::Point> currentMapPoint;
    bool showOwnship, followOwnship;
    bool isMapReady;

    QScopedPointer<SimpleGraphicOverlay> drawingOverlay;
    double originalScale;
    QScopedPointer<EsriRuntimeQt::Envelope> originalExtent;
    bool bPoints;
    QList<EsriRuntimeQt::Point*> pointList;
    bool readyPointList;

    qint64 graphicId;

    bool bSelectPoints;
    bool bTiledLayerVisible;

    QScopedPointer<EsriRuntimeQt::GraphicsLayer> paintLayer;
    QStringList pointListToMGRS(const QList<EsriRuntimeQt::Point>&);
    void paintMgrsGrid(QString &);
     EsriRuntimeQt::Point MGRSToMapPoint(const QString&);
    void mgrsListToLines(const QStringList&, const QStringList&);
    qint64 cropLandGraphicId;
    bool bSelectStartPoint;
    QList<EsriRuntimeQt::Point*> cropLandPointList;
    QScopedPointer<EsriRuntimeQt::Point> startPoint;
    EsriRuntimeQt::Point* getXAxisPoint(const QList<EsriRuntimeQt::Point*>& list, int order);
    QString projectName;
    QString projectPath;

signals:
    void headingChanged(QVariant newHeading);
    void positionChanged(QVariant newPosition);
    void speedChanged(QVariant newSpeed);
    void error( QVariant );
public slots:
    void onMapReady();

    void handleHomeClicked();
    void handlePan(QString direction);
    //    void handlePositionAvailable(QPointF pos, double orientation);

    void handleToggleShowMe(bool state);
    void handleToggleFollowMe(bool state);
    void handleZoomIn();
    void handleZoomOut();
    void handleResetMap();


    void onAvaliblePosition(double, double, double);
    void handlePointsToggled(bool);
    void handleToLinesClicked();
    void handleCreateProjectClicked();
    void handleToPolygonClicked();
    void onClearClicked();
    void mousePress(QMouseEvent);
    void handleSelectPointsToggled(bool);
    void handleGetPathClicked();
    void handlePaintCropLandClicked();
    void handleUnSelectClicked();
    void onMouseWheel(QWheelEvent);
    void onPaintGeometry(const QList<QPointF*> &);
    void handleSelectStartPointClicked();
    void onPaintLineList(QList<EsriRuntimeQt::Line*>);
    void onPaintPathList(QList<EsriRuntimeQt::Line*>);
    void onPaintCornerList(QList<EsriRuntimeQt::Line*>);
    void onToCroplandClicked();
    void handleSaveProjectClicked();
};

}
#endif // MAPCONTROLLER_H
