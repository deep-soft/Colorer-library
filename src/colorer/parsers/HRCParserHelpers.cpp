#include <colorer/parsers/HRCParserHelpers.h>
#include <stdlib.h>


const char* schemeNodeTypeNames[] =  { "EMPTY", "RE", "SCHEME", "KEYWORDS", "INHERIT" };


SchemeNode::SchemeNode()
{
  virtualEntryVector.reserve(5);
  type = SNT_EMPTY;
  schemeName = nullptr;
  scheme = nullptr;
  kwList = nullptr;
  worddiv = nullptr;
  start = end = nullptr;
  lowPriority = 0;

  //!!regions cleanup
  region = nullptr;
  memset(regions, 0, sizeof(regions));
  memset(regionsn, 0, sizeof(regionsn));
  memset(regione, 0, sizeof(regione));
  memset(regionen, 0, sizeof(regionen));
};

SchemeNode::~SchemeNode()
{
  if (type == SNT_RE || type == SNT_SCHEME) {
    delete start;
    delete end;
  }
  if (type == SNT_KEYWORDS) {
    delete kwList;
    delete worddiv;
  }
  if (type == SNT_INHERIT) {
    for (auto it : virtualEntryVector) {
      delete it;
    }
    virtualEntryVector.clear();
  }
}

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

