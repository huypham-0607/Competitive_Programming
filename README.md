# Competitive Programming

Personal archive of competitive programming solutions, mostly in C++. Organized by judge/platform, with each problem in its own folder (typically a `main.cpp` plus optional `note.txt` for approach notes).

## Layout

Each top-level folder is a judge or contest source. Contest folders are further split by contest ID/name, then by problem.

| Folder | Contents |
|---|---|
| `Codeforces/` | Rounds (Div 1/2/3/4, Educational, Global) and individual upsolved problems, by round number/name |
| `Atcoder/` | AtCoder problems, one folder per problem |
| `CSES/` | CSES Problem Set, organized by the site's official topic sections (Intro, Sorting, DP, Graphs, Range Queries, Trees, Math, Strings, Geometry, Advanced) |
| `Olympiad/` | Olympiad-style problems by competition: APIO, BalkanOI, BalticOI, CEOI, COCI, COI, IOI, IZHO, JOI, NOI, POI |
| `USACO/` | USACO problems by division (Bronze, Silver, Gold, Platinum, plus "Old" tiers) |
| `Kattis/`, `SPOJ/`, `Codechef/`, `UVA/`, `HDU/`, `DMOJ/`, `LeetCode/`, `Hackerrank/`, `GoogleKickstart/`, `CSAcademy/`, `kilonova/` | Problems from each respective judge |
| `LibraryChecker/` | Algorithm/data-structure correctness checks (segment tree, DSU, etc.) against Library Checker |
| `VNOJ/` | VNOJ problems, including an LHP (My high school) subset |
| `CP2/`, `CP3/` | Weekly problem sets (`W01`, `W02`, ...) from a competitive programming course |
| `CPU/` | Contests/practice sets run by a competitive programming club (callouts, mock contests, weekly sets) |
| `QOJ/`, `SAPO/`, `MITIT/`, `IPL/` | Problems from named contests/onsite events |
| `Archived/` | Older/inactive material (past teams, misc one-offs) |
| `VJudge/` | Reserved for VJudge-sourced problems |

`Competitive_Programming.code-workspace` ties this repo together with a sibling `Halzyonnn_Templates` repo (algorithm templates/snippets) as a multi-root VS Code workspace.

## Conventions

- Solutions are plain C++ (`main.cpp`), compiled/run directly — no build system.
- Build artifacts (`*.o`, `*.exe`, `*.out`, Code::Blocks project files) and test I/O (`*.in`, `*.inp`, `*.out`, `*.ans`) are gitignored.
- `note.txt` files (where present) hold approach notes/editorial takeaways for a contest or problem.
