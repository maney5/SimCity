#include "Cell.h"

bool Cell::operator==(const Cell& cell) const {
    return (zoneType == cell.zoneType && population == cell.population && availableWorkers == cell.availableWorkers);
}