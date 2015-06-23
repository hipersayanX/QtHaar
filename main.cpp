/* QtHaar, Viola-Jones implementation in Qt.
 * Copyright (C) 2015  Gonzalo Exequiel Pedone
 *
 * QtHaar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QtHaar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QtHaar. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://github.com/hipersayanX/QtHaar
 */

#include <QCoreApplication>
#include <QElapsedTimer>
#include <QPainter>
#include <QtDebug>

#include "haardetector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HaarDetector detector;

    detector.loadCascade("haarcascades/haarcascade_frontalface_alt2.xml");
    QImage image("samples/6049220331_50995e8be8_o.jpg");

//    detector.setEqualize(true);
//    detector.setDenoiseRadius(2);
//    detector.setCannyPruning(true);

    QElapsedTimer elapsedTimer;
    elapsedTimer.start();

    QPainter painter;

    painter.begin(&image);
    painter.setPen(QColor(255, 0, 0));
    painter.drawRects(detector.detect(image));
    painter.end();

    qDebug() << elapsedTimer.elapsed();

    image.save("result.jpg");

    return 0;
}
