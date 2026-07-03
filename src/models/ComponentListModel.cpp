#include "ComponentListModel.h"

ComponentListModel::ComponentListModel(QObject* parent)
    : QAbstractListModel(parent) {}

void ComponentListModel::setData(const std::vector<const Component*>& items,
                                  const QVector<QString>& categories,
                                  const QString& componentType,
                                  const QString& iconSource) {
    beginResetModel();
    m_items = items;
    m_categories = categories;
    m_componentType = componentType;
    m_iconSource = iconSource;
    endResetModel();
    emit countChanged();
}

int ComponentListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(m_items.size());
}

QVariant ComponentListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= (int)m_items.size())
        return {};

    const Component* c = m_items[index.row()];

    switch (role) {
        case NameRole:
            return QString::fromStdString(c->getName()).trimmed();
        case CategoryRole:
            return index.row() < m_categories.size() ? m_categories[index.row()] : QString();
        case ScoreRole:
            return c->calculateScore();
        case TypeRole:
            return QString::fromStdString(c->getType());
        case SpeedGroundRole:
            return c->getSpeedGround();
        case SpeedWaterRole:
            return c->getSpeedWater();
        case SpeedAirRole:
            return c->getSpeedAir();
        case SpeedAntiGRole:
            return c->getSpeedAntiG();
        case AccelerationRole:
            return c->getAcceleration();
        case WeightRole:
            return c->getWeight();
        case HandlingGroundRole:
            return c->getHandlingGround();
        case HandlingWaterRole:
            return c->getHandlingWater();
        case HandlingAirRole:
            return c->getHandlingAir();
        case HandlingAntiGRole:
            return c->getHandlingAntiG();
        case TractionRole:
            return c->getTraction();
        case IconRole:
            return m_iconSource;
        case ItemIndexRole:
            return index.row();
        default:
            return {};
    }
}

QHash<int, QByteArray> ComponentListModel::roleNames() const {
    return {
        { NameRole, "name" },
        { CategoryRole, "category" },
        { ScoreRole, "score" },
        { TypeRole, "componentType" },
        { SpeedGroundRole, "speedGround" },
        { SpeedWaterRole, "speedWater" },
        { SpeedAirRole, "speedAir" },
        { SpeedAntiGRole, "speedAntiG" },
        { AccelerationRole, "acceleration" },
        { WeightRole, "weight" },
        { HandlingGroundRole, "handlingGround" },
        { HandlingWaterRole, "handlingWater" },
        { HandlingAirRole, "handlingAir" },
        { HandlingAntiGRole, "handlingAntiG" },
        { TractionRole, "traction" },
        { IconRole, "icon" },
        { ItemIndexRole, "itemIndex" },
    };
}

QVariantMap ComponentListModel::get(int index) const {
    QVariantMap map;
    if (index < 0 || index >= (int)m_items.size()) return map;
    const auto roles = roleNames();
    for (auto it = roles.constBegin(); it != roles.constEnd(); ++it)
        map[QString::fromUtf8(it.value())] = data(this->index(index), it.key());
    return map;
}
