## [1.5.0] - xxxx-xx-xx

### Added
- Working with hrcsettings.xml added to the core. If the path to hrcsettings.xml omitted, the environment variable COLORER_HRC_SETTINGS is used.
- A parameter for hrcsettings has been added to consoletools
- A parameter for folder with user hrc-files has been added to consoletools

### Changed
- The new package attribute is "global". The default value is "yes".
- Separate loading of different hrc parts:
  - at the prototype loading stage, only prototypes and global packages are loaded.
  - at the type loading stage, only types and local packages are loaded.
- Exclude *.ent.hrc files from the prototype loading stage
- The -f (forward) parameter has been removed in consoletools

## [1.4.2] - 2025-05-24

### Fixed
- Fix reading non-latin string from hrc file
- Crash when open file on net symlinked folder
- In 'keywords', for the case ignorecase="yes", similar words specified in different case were incorrectly processed.
- if a substring of a word is also present in the 'keywords' list, then the substring word might not be highlighted. For example, for couples "!=" and "!".

## [1.4.1] - 2024-11-02

### Fixed
- Creation of log files when logging is disabled
- Reading a schema from files whose path contains non-Latin letters :
  - incorrect conversion between char and char16 on Windows
  - error reading external entities in xml files on Linux, feature or bug libxml2

## [1.4.0] - 2024-10-18

### Added
- Two options for working with strings are ICU and the old implementation of colorer

### Fixed
- Build on old Linux platform. A minimum of gcc 7 is required.
- Build on Linux ARM64, *BSD, macOS
- Fixed a bug/freeze when resizing the window in which a paired object is selected
 
### Changed
- The library for logging spdlog has been replaced by own implementation.
- The library for working with xml Xerces-c has been replaced by LibXml2.
- The environment variables in the path for the external entity in xml should be set in the format $ENV, 
   and the path should be preceded by 'env:' for files or 'jar:' for archives.

## [1.3.3] - 2024-03-16

### Fixed

- The length of the string used to detecting the file type takes into account the length restrictions
- Memory leak on reading xml files
- Removed unnecessary checks for keywords, which increased the speed
- Reduced memory consumption for storing schemes

## [1.3.2] - 2024-01-20

### Fixed

- Again: Work with catalog.xml on fat32 filesystem. Changed compiler version.

## [1.3.1] - 2023-04-01

### Fixed

- Work with catalog.xml on fat32 filesystem ([#26](https://github.com/colorer/Colorer-library/issues/26))

## [1.3.0] - 2021-05-12

### Added

- Add work with symlinks. If file is symlink, for example catalog.xml, we work with real file and full path to it ([#10](https://github.com/colorer/Colorer-library/issues/10))
- Add work with system environments in path to files
- Add work with zip entity. Support new type of schemes 'allpacked'

### Changed

- In base/hrc/auto folder (and same in catalog.xml) search only *.hrc files ([#20](https://github.com/colorer/Colorer-library/issues/20))

## [1.2.1] - 2021-04-03

First auto built release

## [1.2.0] - 2021-09-09

### Changed

- Work with redirect stdin as input file, detect charset if set BOM ([#8](https://github.com/colorer/Colorer-library/issues/8))

### Fixed

- Fix crash on invalid zip file name ([#15](https://github.com/colorer/Colorer-library/issues/15))
- colorertools: fix crash if did not detect file type and did not input filename

## [1.1.1] - 2021-02-28

### Fixed

- Fix output log messages to stdout if log level equal 'off' ([#14](https://github.com/colorer/Colorer-library/issues/14))

### Changed

- Set default log level value to 'off'

## [1.1.0] - 2021-02-28

### Changed

- Change license to MIT
- Change internal Unicode library to ICU
- Get dependencies for build from vcpkg

### Added

- regexp: add support ignorecase for symbol class
- add new property for TextParser - maximum block size of regexp in string line

### Fixed

- Fix error when searching for the missing type
- Fix duplicate entries in outliner https://github.com/colorer/FarColorer/issues/25

### Removed

- Remove dlmalloc library
- Remove working with different charsets. Input files only in Unicode, output only in UTF-8.

## [1.0.4] - 2019-01-29

### Changed

- Update xerces-c
- Update zlib
- Add spdlog
- Remove g3log

## [1.0.3] - 2018-12-09

### Fixed

- Fixed incorrect file type detection

## [1.0.2] - 2016-06-18

### Changed

- optimized

## [1.0.1] - 2016-02-06

### Changed

- logging default off
- add settings for logging

## [1.0.0] - 2016-01-23

### Changed

- add version info
- add asynchronous logging

