#ifndef MUSICWIDGETALBUM_H
#define MUSICWIDGETALBUM_H

#include <QLineEdit>
#include <QPointer>
#include <QWidget>
#include "../smallWidgets/ClosableImage.h"
#include "../music/Album.h"

namespace Ui {
class MusicWidgetAlbum;
}

class MusicWidgetAlbum : public QWidget
{
    Q_OBJECT

public:
    explicit MusicWidgetAlbum(QWidget *parent = 0);
    ~MusicWidgetAlbum();
    void setAlbum(Album *album);

public slots:
    void onSetEnabled(bool enabled);
    void onClear();
    void onSaveInformation();
    void onStartScraperSearch();

signals:
    void sigSetActionSearchEnabled(bool, MainWidgets);
    void sigSetActionSaveEnabled(bool, MainWidgets);
    void sigDownloadsStarted(QString,int);
    void sigDownloadsProgress(int,int,int);
    void sigDownloadsFinished(int);

private slots:
    void onRevertChanges();
    void onItemChanged(QString text);
    void onRatingChanged(double value);
    void onYearChanged(int value);
    void onReviewChanged();
    void onAddCloudItem(QString text);
    void onRemoveCloudItem(QString text);
    void onChooseImage();
    void onDeleteImage();
    void onInfoLoadDone(Album *album);
    void onLoadDone(Album *album);
    void onDownloadProgress(Album *album, int current, int maximum);
    void onLoadingImages(Album *album, QList<int> imageTypes);
    void onLoadImagesStarted(Album *album);
    void onSetImage(Album *album, int type, QByteArray data);

private:
    Ui::MusicWidgetAlbum *ui;
    QPointer<Album> m_album;

    void updateAlbumInfo();
    void clearContents(QLineEdit *widget);
    void setContent(QLineEdit *widget, const QString &content);
    void updateImage(int imageType, ClosableImage *image);
};

#endif // MUSICWIDGETALBUM_H
