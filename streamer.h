#ifndef STREAMER_H
#define STREAMER_H

#include <QMap>
#include <QList>
#include <QDomDocument>
#include <QFile>
#include <QtXml>

class Streamer
{
public:
    Streamer();
    QMap<QString, QString> streamer;
    QList<QString> streamerNameList;

private:
    void GetAllStreamer();
};

#endif // STREAMER_H
