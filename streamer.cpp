#include "streamer.h"

Streamer::Streamer()
{
    GetAllStreamer();
}

void Streamer::GetAllStreamer()
{
    QFile file("Streamer.xml");
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QDomDocument dom;
            if (dom.setContent(&file))
            {
                QDomElement docElem = dom.documentElement();
                QDomNode node = docElem.firstChild();

                while (!node.isNull()) {
                    QString name = node.attributes().namedItem("name").nodeValue();
                    QString url = node.attributes().namedItem("url").nodeValue();
                    streamer.insert(name, url);
                    streamerNameList.append(name);

                    node = node.nextSibling();
                }
            }
        }
    }

}
