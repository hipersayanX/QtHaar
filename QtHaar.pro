# QtHaar, Viola-Jones implementation in Qt.
# Copyright (C) 2015  Gonzalo Exequiel Pedone
#
# QtHaar is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# QtHaar is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with QtHaar. If not, see <http://www.gnu.org/licenses/>.
#
# Email   : hipersayan DOT x AT gmail DOT com
# Web-Site: http://github.com/hipersayanX/QtHaar

QT += core gui concurrent

TARGET = QtHaar
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    haarcascade.cpp \
    haarstage.cpp \
    haartree.cpp \
    haarfeature.cpp \
    haardetector.cpp

HEADERS += \
    haarcascade.h \
    haarstage.h \
    haartree.h \
    haarfeature.h \
    haardetector.h
