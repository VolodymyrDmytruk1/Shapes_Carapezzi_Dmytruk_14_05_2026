/*! \file CRectangle.h
    \brief Declaration of the class Rectangle
*/

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "CShape.h"

/// @class Rectangle
/// @brief to manage an object with the shape of a rectangle
class RightTringle : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    RightTringle();
    RightTringle(float px, float py, float w, float h);
    RightTringle(const RightTringle &r);

    ~Rectangle();
    /// @}

    /// @name OPERATORS
    /// @{
    RightTringle& operator=(const RightTringle &r);
    bool operator==(const RightTringle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const RightTringle &r);
    void Reset();
    /// @}
	
	/// @name GETTERS
    /// @{
	float GetVSide();
	float GetHSide();
	float GetHypotenuse();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}
};

#endif
