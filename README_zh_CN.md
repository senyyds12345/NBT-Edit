# 描述
- Nbt-edit 是一个轻量级且便捷的 NBT 工具，提供命令行 NBT 工具、glibc 的 libnbt 库以及静态 NBT 库

# 使用
- 安装后，你可以通过 nbt 命令在命令行中与 NBT 交互。你可以通过输入命令来添加 NBT 标签和值
- 以下是交互式 NBT 管理器的命令

| 命令 | 描述 |
| :--- | :--- |
| TAG 1 | 添加一个 Byte 类型标签 |
| TAG 2 | 添加一个 Short 类型标签 |
| TAG 3 | 添加一个 Int 类型标签 |
| TAG 4 | 添加一个 Float 类型标签 |

- libnbt 库的使用方法可以在源码中找到

# 安装
- 构建
```bash
dpkg-deb --build . NBT-Edit.deb