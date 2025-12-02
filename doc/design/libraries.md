# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libfixedcoin_cli*         | RPC client functionality used by *fixedcoin-cli* executable |
| *libfixedcoin_common*      | Home for common functionality shared by different executables and libraries. Similar to *libfixedcoin_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libfixedcoin_consensus*   | Stable, backwards-compatible consensus functionality used by *libfixedcoin_node* and *libfixedcoin_wallet* and also exposed as a [shared library](../shared-libraries.md). |
| *libfixedcoinconsensus*    | Shared library build of static *libfixedcoin_consensus* library |
| *libfixedcoin_kernel*      | Consensus engine and support library used for validation by *libfixedcoin_node* and also exposed as a [shared library](../shared-libraries.md). |
| *libfixedcoinqt*           | GUI functionality used by *fixedcoin-qt* and *fixedcoin-gui* executables |
| *libfixedcoin_ipc*         | IPC functionality used by *fixedcoin-node*, *fixedcoin-wallet*, *fixedcoin-gui* executables to communicate when [`--enable-multiprocess`](multiprocess.md) is used. |
| *libfixedcoin_node*        | P2P and RPC server functionality used by *fixedcoind* and *fixedcoin-qt* executables. |
| *libfixedcoin_util*        | Home for common functionality shared by different executables and libraries. Similar to *libfixedcoin_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libfixedcoin_wallet*      | Wallet functionality used by *fixedcoind* and *fixedcoin-wallet* executables. |
| *libfixedcoin_wallet_tool* | Lower-level wallet functionality used by *fixedcoin-wallet* executable. |
| *libfixedcoin_zmq*         | [ZeroMQ](../zmq.md) functionality used by *fixedcoind* and *fixedcoin-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. Exceptions are *libfixedcoin_consensus* and *libfixedcoin_kernel* which have external interfaces documented at [../shared-libraries.md](../shared-libraries.md).

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`libfixedcoin_*_SOURCES`](../../src/Makefile.am) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libfixedcoin_node* code lives in `src/node/` in the `node::` namespace
  - *libfixedcoin_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libfixedcoin_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libfixedcoin_util* code lives in `src/util/` in the `util::` namespace
  - *libfixedcoin_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

fixedcoin-cli[fixedcoin-cli]-->libfixedcoin_cli;

fixedcoind[fixedcoind]-->libfixedcoin_node;
fixedcoind[fixedcoind]-->libfixedcoin_wallet;

fixedcoin-qt[fixedcoin-qt]-->libfixedcoin_node;
fixedcoin-qt[fixedcoin-qt]-->libfixedcoinqt;
fixedcoin-qt[fixedcoin-qt]-->libfixedcoin_wallet;

fixedcoin-wallet[fixedcoin-wallet]-->libfixedcoin_wallet;
fixedcoin-wallet[fixedcoin-wallet]-->libfixedcoin_wallet_tool;

libfixedcoin_cli-->libfixedcoin_util;
libfixedcoin_cli-->libfixedcoin_common;

libfixedcoin_common-->libfixedcoin_consensus;
libfixedcoin_common-->libfixedcoin_util;

libfixedcoin_kernel-->libfixedcoin_consensus;
libfixedcoin_kernel-->libfixedcoin_util;

libfixedcoin_node-->libfixedcoin_consensus;
libfixedcoin_node-->libfixedcoin_kernel;
libfixedcoin_node-->libfixedcoin_common;
libfixedcoin_node-->libfixedcoin_util;

libfixedcoinqt-->libfixedcoin_common;
libfixedcoinqt-->libfixedcoin_util;

libfixedcoin_wallet-->libfixedcoin_common;
libfixedcoin_wallet-->libfixedcoin_util;

libfixedcoin_wallet_tool-->libfixedcoin_wallet;
libfixedcoin_wallet_tool-->libfixedcoin_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class fixedcoin-qt,fixedcoind,fixedcoin-cli,fixedcoin-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Consensus* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libfixedcoin_wallet* and *libfixedcoin_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libfixedcoin_consensus* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libfixedcoin_util* should also be a standalone dependency that any library can depend on, and it should not depend on other internal libraries.

- *libfixedcoin_common* should serve a similar function as *libfixedcoin_util* and be a place for miscellaneous code used by various daemon, GUI, and CLI applications and libraries to live. It should not depend on anything other than *libfixedcoin_util* and *libfixedcoin_consensus*. The boundary between _util_ and _common_ is a little fuzzy but historically _util_ has been used for more generic, lower-level things like parsing hex, and _common_ has been used for fixedcoin-specific, higher-level things like parsing base58. The difference between util and common is mostly important because *libfixedcoin_kernel* is not supposed to depend on *libfixedcoin_common*, only *libfixedcoin_util*. In general, if it is ever unclear whether it is better to add code to *util* or *common*, it is probably better to add it to *common* unless it is very generically useful or useful particularly to include in the kernel.


- *libfixedcoin_kernel* should only depend on *libfixedcoin_util* and *libfixedcoin_consensus*.

- The only thing that should depend on *libfixedcoin_kernel* internally should be *libfixedcoin_node*. GUI and wallet libraries *libfixedcoinqt* and *libfixedcoin_wallet* in particular should not depend on *libfixedcoin_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be get able it from *libfixedcoin_consensus*, *libfixedcoin_common*, and *libfixedcoin_util*, instead of *libfixedcoin_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libfixedcoinqt*, *libfixedcoin_node*, *libfixedcoin_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](`../../src/interfaces/`) abstract interfaces.

## Work in progress

- Validation code is moving from *libfixedcoin_node* to *libfixedcoin_kernel* as part of [The libfixedcoinkernel Project #24303](https://github.com/fixedcoin/fixedcoin/issues/24303)
- Source code organization is discussed in general in [Library source code organization #15732](https://github.com/fixedcoin/fixedcoin/issues/15732)
