## Changelog v1.4.0

References | Description | Author(s)
--- | --- | ---
#703 | NetBSD Support | @fraggerfox
#903 | Intel GPU support | @bjia56
161e8f4 | Added warnings when toggling boxes and terminal size is to small | @aristocratos
4210f5f | Fix missing core percentages, issue #792 | @aristocratos
35857f8 | Various fixes for drawing GPU related information | @aristocratos
#879 | fix divide 0 error when caculating disk usage percentage (#791) | @flylai
#884 | fix io_graph_speeds parsing | @feihtthief
#863 | V1 of Phoenix Night theme | @Firehawke
3f384c0 | Fixed missing CPU core temps when too small to show core temp graphs, issues #792 #867 | @aristocratos
97d2fb5 | Fixed missing IO graphs in IO mode, issue #867 | @aristocratos
#840 | fix zero temp (#467) | @joske
#850 | Fix comments (parsing) in theme files | @acidghost
#806 | Add regex filtering | @imwints
#836 | Fix typo in file existences check for voltage_now | @vsey
#835 | Show time in days when remaining battery exceeds an estimation of 24h | @imwints
#819 | (AMD Gpu) fix pwr_usage not being defined correctly during rsmi collection | @kalkafox
#831 | macOS: fix crash if there exists a uid not associated with any user | @thecoder-001
#796 | Fix rsmi device name buffer size | @davc0n
#807 | Add gruvbox_light theme | @kk9uk
#724 | Create man page for btop in Markdown | @ottok
#734 | Include metadata in binary version output `btop --version` | @imwints
#771 | collect: Fix reading of battery power draw on Linux | @Derppening

**For additional binaries see the [Continuous Builds](https://github.com/aristocratos/btop/actions).**

**Linux binaries for each architecture are statically linked with musl and works on kernel 2.6.39 and newer.**

**No MacOs or BSD binaries provided for the moment.**

**Notice! None of the binaries have GPU support, compile yourself or wait for distribution packages for GPU monitoring support!**

**Notice! Use x86_64 for 64-bit x86 systems, i486 and i686 are 32-bit!**
