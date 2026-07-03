#ifndef BUILDLISTMODEL_H
#define BUILDLISTMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "../core/Build.h"

// Modelo para listas de resultados de Build (ranking top-N y builds similares).
class BuildListModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum Roles {
        RankRole = Qt::UserRole + 1,
        DriverNameRole,
        BodyNameRole,
        TireNameRole,
        GliderNameRole,
        ScoreRole,
        BarRatioRole,      // 0..1 relativo al mejor score de la lista, para animar barras
        DistanceRole       // usado solo en la vista de similitud (0 en ranking)
    };
    Q_ENUM(Roles)

    explicit BuildListModel(QObject* parent = nullptr);

    void setBuilds(const std::vector<Build>& builds,
                   const std::vector<double>& distances = {});

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    int count() const { return static_cast<int>(m_builds.size()); }

signals:
    void countChanged();

private:
    std::vector<Build> m_builds;
    std::vector<double> m_distances;
    double m_maxScore = 1.0;
    double m_minScore = 0.0;
};

#endif
