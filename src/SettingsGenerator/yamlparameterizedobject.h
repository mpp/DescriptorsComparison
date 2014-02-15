/*!
 * \file yamlparameterizedobject.h
 * \author Michele Marostica
 * \brief This is a base class that contains the object name and its parameters that
 *        come from a .yml file
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Michele Marostica - michele[dot]marostica[at]dei[dot]unipd[dot]it
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef YAMLPARAMETERIZEDOBJECT_H
#define YAMLPARAMETERIZEDOBJECT_H

#include <string>
#include <map>
#include <memory>

namespace sgt {

typedef std::string param_name;
typedef std::string param_value;
typedef std::map<param_name, param_value> parameters;

class YAMLParameterizedObject
{
public:

    typedef std::shared_ptr<YAMLParameterizedObject> Ptr;
    typedef std::shared_ptr<const YAMLParameterizedObject> ConstPtr;

    /*!
     * \brief YAMLParameterizedObject
     * \param name
     * \param params
     */
    YAMLParameterizedObject(std::string name,
                            parameters params);

    /*!
     * \brief getName
     * \return Return the object name
     */
    std::string getName() const;

    /*!
     * \brief getParameters
     * \return Return the object parameters
     */
    parameters getParameters() const;

// Private members
private:

// Private data
private:

    std::string
        name_;          //!< The name of the object

    parameters
        parameters_;    //!< The map with the parameters and their name

};

} // namespace sgt

#endif // YAMLPARAMETERIZEDOBJECT_H
