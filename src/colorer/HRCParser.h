#ifndef _COLORER_HRCPARSER_H_
#define _COLORER_HRCPARSER_H_

#include<colorer/io/InputSource.h>

#include<colorer/FileType.h>
#include<colorer/Region.h>
#include <colorer/xml/XmlInputSource.h>


/** Informs application about internal HRC parsing problems.
    @ingroup colorer
*/
class HRCParserException : public Exception
{
public:
  HRCParserException() noexcept : Exception("[HRCParserException] ") {};
  HRCParserException(const String &msg) noexcept : HRCParserException()
  {
    what_str.append(msg.getChars());
  }
  HRCParserException(const std::string &msg) noexcept :
    HRCParserException()
  {
    what_str.append(msg);
  }
};


/** Abstract template of HRCParser class implementation.
    Defines basic operations of loading and accessing
    HRC information.
    @ingroup colorer
*/
class HRCParser
{
public:
  /** Loads HRC from specified InputSource stream.
      Referred HRC file can contain prototypes and
      real types definitions. If it contains just prototype definition,
      real type load must be performed before using with #loadType() method
      @param is InputSource stream of HRC file
  */
  virtual void loadSource(XmlInputSource *is) = 0;

  /** Enumerates sequentially all prototypes
      @param index index of type.
      @return Requested type, or null, if #index is too big
  */
  virtual FileType *enumerateFileTypes(int index) = 0;

  /** @param name Requested type name.
      @return File type, or null, there are no type with specified name.
  */
  virtual FileType *getFileType(const String *name) = 0;

  /** Searches and returns the best type for specified file.
      This method uses fileName and firstLine parameters
      to perform selection of the best HRC type from database.
      @param fileName Name of file
      @param firstLine First line of this file, could be null
      @param typeNo Sequential number of type, if more than one type
                    satisfy these input parameters.
  */
  virtual FileType *chooseFileType(const String *fileName, const String *firstLine, int typeNo = 0) = 0;

  virtual size_t getFileTypesCount() = 0;

  /** Total number of declared regions
  */
  virtual size_t getRegionCount() = 0;
  /** Returns region by internal id
  */
  virtual const Region *getRegion(int id) = 0;
  /** Returns region by name
      @note Also loads referred type, if it is not yet loaded.
  */
  virtual const Region *getRegion(const String *name) = 0;

  /** HRC base version.
      Usually this is the 'version' attribute of 'hrc' element
      of the first loaded HRC file.
  */
  virtual const String *getVersion() = 0;

  virtual ~HRCParser(){};
protected:
  HRCParser(){};
};


#endif
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Colorer Library.
 *
 * The Initial Developer of the Original Code is
 * Cail Lomecb <irusskih at gmail dot com>.
 * Portions created by the Initial Developer are Copyright (C) 1999-2009
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s): see file CONTRIBUTORS
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
