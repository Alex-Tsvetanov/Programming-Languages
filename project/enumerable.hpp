/**
 * @file enumerable.hpp
 * @brief Contains the declaration of the `IEnumerable` class, which provides a unique identifier for derived objects.
 */

#pragma once
#include "project_fwd_def.hpp"

/**
 * @class IEnumerable
 * @brief A base class that provides unique IDs for objects. 
 * 
 * This class is designed to assign a unique identifier to each instance of a derived class.
 */
class IEnumerable
{
    /**
     * @brief Tracks the next available unique ID.
     */
    static unsigned int next_id;

    /**
     * @brief The unique ID assigned to the object.
     */
    unsigned int id;

public:
    /**
     * @brief Default constructor. Assigns a unique ID to the instance.
     */
    IEnumerable()
    {
        id = next_id++;
    }

    /**
     * @brief Retrieves the unique ID of the instance.
     * @return The unique ID of the object.
     */
    virtual inline unsigned int get_id() const final
    {
        return id;
    }

    /**
     * @brief Declares AirSpaceManager as a friend class, allowing it to access private members.
     */
    friend class AirSpaceManager;
};
