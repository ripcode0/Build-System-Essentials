## clang-format on vscode

#### requirement extensions

* Clang-Format : xaver.clang-format
* YAML Languages : Support by Red Hat (optional for intelligent)

#### intelligent auto-completion

```json
# settings.json
{
    "editor.formatOnSave": true,
    "yaml.schemas": {
        "https://json.schemastore.org/clang-format": "**/.clang-format"
    }
}
```

#### to creating default clang-format

```bash
clang-format -style=llvm -dump-config > .clang-format
```

#### syntax

* As the version has increased, most options that used to be true or false have been replaced with specific keywords.
You can refer to examples for guidance.

```bash
clang-format -dump-config > syntax.txt
```

