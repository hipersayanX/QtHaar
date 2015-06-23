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

#ifndef HAARTREE_H
#define HAARTREE_H

#include "haarfeature.h"

class HaarTree;

typedef QVector<HaarTree> HaarTreeVector;

class HaarTreeHID
{
    public:
        explicit HaarTreeHID(const HaarTree &tree,
                             int oWidth,
                             const quint32 *integral,
                             const quint32 *tiltedIntegral,
                             qreal invArea,
                             qreal scale);
        ~HaarTreeHID();

        int m_count;
        HaarFeatureHID **m_features;

        inline qreal eval(size_t offset, qreal varianceNormFactor) const
        {
            int idx = 0;
            qreal treeValue;

            forever {
                const HaarFeatureHID *feature = this->m_features[idx];

                if (feature->goLeft(offset, varianceNormFactor)) {
                    if (feature->m_leftNode < 0) {
                        treeValue = feature->m_leftVal;

                        break;
                    }
                    else
                        idx = feature->m_leftNode;
                } else {
                    if (feature->m_rightNode < 0) {
                        treeValue = feature->m_rightVal;

                        break;
                    }
                    else
                        idx = feature->m_rightNode;
                }
            }

            return treeValue;
        }
};

class HaarTree: public QObject
{
    Q_OBJECT

    public:
        explicit HaarTree(QObject *parent = NULL);
        HaarTree(const HaarTree &other);
        ~HaarTree();

        Q_INVOKABLE HaarFeatureVector features() const;
        Q_INVOKABLE HaarFeatureVector &features();

        HaarTree &operator =(const HaarTree &other);
        bool operator ==(const HaarTree &other) const;
        bool operator !=(const HaarTree &other) const;

    private:
        HaarFeatureVector m_features;

    signals:
        void featuresChanged(const HaarFeatureVector &features);

    public slots:
        void setFeatures(const HaarFeatureVector &features);
        void resetFeatures();

    friend class HaarTreeHID;
};

#endif // HAARTREE_H
