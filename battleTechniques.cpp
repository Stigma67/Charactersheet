#include "battleTechniques.hpp"

BattleTechniques::BattleTechniques()
{
}

BattleTechniques::Weapons::Weapons(WeaponTypes weaponType)
: WidgetItemWeaponType(new QTableWidgetItem)
, WidgetItemSkill(new QTableWidgetItem)
, WidgetItemAttack(new QTableWidgetItem)
, WidgetItemParry(new QTableWidgetItem)
, SpinBoxAP(new QSpinBox)
{
}

void BattleTechniques::setWeaponType(WeaponTypes weaponType)
{
	switch (weaponType) {
		case ARMBRUEST:
		{

			break;
		}
		case BOEGEN:
		{

			break;
		}
		case DOLCH:
		{

			break;
		}
		case HIEBWAFFE:
		{

			break;
		}
		case KETTENWAFFE:
		{

			break;
		}
		case LANZE:
		{

			break;
		}
		case PEITSCHE:
		{

			break;
		}
		case RAUFEN:
		{

			break;
		}
		case SCHILD:
		{

			break;
		}
		case SCHLEUDER:
		{

			break;
		}
		case SCHWERT:
		{

			break;
		}
		case WURFWAFFE:
		{

			break;
		}
		default:
		{
			break;
		}
	}
}
