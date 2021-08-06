#pragma once

#include <types.hpp>
#include <values.hpp>
#include <player.hpp>
#include <component.hpp>

enum VariableType {
	VariableType_None,
	VariableType_Int,
	VariableType_String,
	VariableType_Float
};

struct IVariableStorageBase {
	/// Set a variable to a string
	virtual void setString(StringView key, StringView value) = 0;
	
	/// Get a variable as a string
	virtual const StringView getString(StringView key) const = 0;

	/// Set a variable to an int
	virtual void setInt(StringView key, int value) = 0;

	/// Get a variable as an int
	virtual int getInt(StringView key) const = 0;

	/// Set a variable to a float
	virtual void setFloat(StringView key, float value) = 0;

	/// Get a variable as a float
	virtual float getFloat(StringView key) const = 0;

	/// Get a variable's type
	virtual VariableType getType(StringView key) const = 0;

	/// Erase a variable, freeing its memory
	virtual bool erase(StringView key) = 0;
};

static const UUID VariablesComponent_UUID = UUID(0x75e121848bc01fa2);
struct IVariablesComponent : public IComponent, public IVariableStorageBase {
	PROVIDE_UUID(VariablesComponent_UUID);
};

static const UUID PlayerVariableData_UUID = UUID(0x12debbc8a3bd23ad);
struct IPlayerVariableData : public IPlayerData, public IVariableStorageBase {
	PROVIDE_UUID(PlayerVariableData_UUID);
};