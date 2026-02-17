# Description
- Nbt-edit is a lightweight and convenient nbt tool that offers command-line NBT tools, glibc's libnbt library, and static nbt libraries
# use
- After installation, you can interact with nbt in the command line by using the nbt command. You can add nbt tags and values by entering the command
- The following are the commands for the interactive nbt manager

| command | description |
| :--------- | :----------- |
| TAG 1 | Add a Byte type tag |
| TAG 2 | Add a Short type tag |
| TAG 3 | Add a Int type tag |
| TAG 4 | Add a Float type tag |

- The usage method of the libnbt library can be found in the source code
# Install
- Please delete the libnbt folder before building
- Build
``` bash
dpkg-deb --build . NBT-Edit.deb
`
- Install using dpkg
``` bash
dpkg -i NBT-Edit.deb
`