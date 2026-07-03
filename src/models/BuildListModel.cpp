#include "BuildListModel.h"
#include <algorithm>

BuildListModel::BuildListModel(QObject* parent) : QAbstractListModel(parent) {}

void BuildListModel::setBuilds(const std::vector<Build>& builds, const std::vector<double>& distances) {
    beginResetModel();
    m_builds = builds;
    m_distances = distances;

    m_maxScore = 1.0;
    m_minScore = 0.0;
    if (!m_builds.empty()) {
        auto mm = std::minmax_element(m_builds.begin(), m_builds.end(),
            [](const Build& a, const Build& b) { return a.getPerformanceScore() < b.getPerformanceScore(); });
        m_minScore = mm.first->getPerformanceScore();
        m_maxScore = mm.second->getPerformanceScore();
        if (m_maxScore - m_minScore < 0.0001) m_maxScore = m_minScore + 1.0;
    }
    endResetModel();
    emit countChanged();
}

int BuildListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(m_builds.size());
}

QVariant BuildListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= (int)m_builds.size())
        return {};

    const Build& b = m_builds[index.row()];

    switch (role) {
        case RankRole:
            return index.row() + 1;
        case DriverNameRole:
            return QString::fromStdString(b.getDriver()->getName()).trimmed();
        case BodyNameRole:
            return QString::fromStdString(b.getBody()->getName()).trimmed();
        case TireNameRole:
            return QString::fromStdString(b.getTire()->getName()).trimmed();
        case GliderNameRole:
            return QString::fromStdString(b.getGlider()->getName()).trimmed();
        case ScoreRole:
            return b.getPerformanceScore();
        case BarRatioRole: {
            double range = m_maxScore - m_minScore;
            double ratio = range > 0.0001 ? (b.getPerformanceScore() - m_minScore) / range : 1.0;
            return 0.12 + ratio * 0.88; // deja un piso visible aun en el peor build
        }
        case DistanceRole:
            return (index.row() < (int)m_distances.size()) ? m_distances[index.row()] : 0.0;
        default:
            return {};
    }
}

QHash<int, QByteArray> BuildListModel::roleNames() const {
    return {
        { RankRole, "rank" },
        { DriverNameRole, "driverName" },
        { BodyNameRole, "bodyName" },
        { TireNameRole, "tireName" },
        { GliderNameRole, "gliderName" },
        { ScoreRole, "score" },
        { BarRatioRole, "barRatio" },
        { DistanceRole, "distance" },
    };
}
