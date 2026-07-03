#ifndef COMPONENTLISTMODEL_H
#define COMPONENTLISTMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <vector>

#include "../core/Component.h"

// Modelo generico (capa "Model" del MVVM expuesta a QML) que envuelve
// cualquier catalogo de Component* (Driver, Body, Tire o Glider).
// No es dueno de la memoria: los punteros viven en AppController.
class ComponentListModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QString componentType READ componentType CONSTANT)
    Q_PROPERTY(QString iconSource READ iconSource CONSTANT)
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        CategoryRole,
        ScoreRole,
        TypeRole,
        SpeedGroundRole,
        SpeedWaterRole,
        SpeedAirRole,
        SpeedAntiGRole,
        AccelerationRole,
        WeightRole,
        HandlingGroundRole,
        HandlingWaterRole,
        HandlingAirRole,
        HandlingAntiGRole,
        TractionRole,
        IconRole,
        ItemIndexRole
    };
    Q_ENUM(Roles)

    explicit ComponentListModel(QObject* parent = nullptr);

    // items: punteros no propietarios; categories: subtipo opcional
    // (Small/Medium/Large para Driver, Kart/Bike/ATV para Body, "" resto).
    void setData(const std::vector<const Component*>& items,
                 const QVector<QString>& categories,
                 const QString& componentType,
                 const QString& iconSource);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    QString componentType() const { return m_componentType; }
    QString iconSource() const { return m_iconSource; }
    int count() const { return static_cast<int>(m_items.size()); }

    Q_INVOKABLE QVariantMap get(int index) const;

signals:
    void countChanged();

private:
    std::vector<const Component*> m_items;
    QVector<QString> m_categories;
    QString m_componentType;
    QString m_iconSource;
};

#endif
