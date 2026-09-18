# [Project Name] — Sandbox Spellcraft Game

*Unreal Engine 5.8.2 — Blueprint & C++*

A sandbox game built around a **Spell Crafting system**, where players combine
different "Runes" to create spells with varying effects, and cast them into a
fully destructible, physics-driven environment powered by Unreal's Chaos system.

<img width="1280" height="720" alt="Screenshot 2026-09-18 165118" src="https://github.com/user-attachments/assets/d6ecf3d2-5820-48b2-ac67-948df427df06" />

---

## Table of Contents

1. [Project Architecture](#project-architecture)
2. [Main Classes / Blueprints / Components](#main-classes--blueprints--components)
3. [Interaction System](#interaction-system)
4. [Physics Systems](#physics-systems)
5. [Main Technical Choices](#main-technical-choices)
6. [AI Statement of Intent](#ai-statement-of-intent)

---

## Project Architecture

The project is a **sandbox game** built in Unreal Engine 5.8.2, combining
**C++** (for core, performance-sensitive, or data-driven logic) and
**Blueprints** (for gameplay iteration, UI, and designer-facing logic).

No strict architectural pattern (e.g. MVC, ECS) was enforced across the
project. Instead, the codebase is organized around two main functional
pillars:

- **The Spellcraft system**: players collect/select "Runes" and combine them
  through a crafting interface to produce spells with different effects
  (damage, force, elemental effects, etc.).
- **The Destruction/Physics layer**: built on Unreal's **Chaos Destruction**
  system, allowing cast spells to physically affect the environment
  (fracturing geometry, applying force, etc.).

---

## Main Classes / Blueprints / Components

| Name | Type | Description |
|---|---|---|
| `FCraftingRecipe` | C++ Struct (inherits `UDataTable` row) | Defines a crafting recipe: registers which combination of Runes produces which spell, and stores the associated data used by the crafting system. |
| `ASpellBase` | C++ Class (Actor) | Base class for all spells in the game. Handles shared spell behavior (casting, applying effects, interacting with the world) and is extended/specialized per spell type. |
| `WBP_SpellMenu` | Blueprint Widget | The player-facing crafting UI. Contains the logic for selecting Runes, validating combinations against `FCraftingRecipe` entries, and triggering spell creation. |

> Additional Blueprint subclasses of `ASpellBase` were created per spell
> effect/type as the system was extended during development.

<img width="1280" height="720" alt="Screenshot 2026-09-18 165249" src="https://github.com/user-attachments/assets/c35a0235-e7a6-4359-bd30-50eb7961abfa" />

---

## Interaction System

The core interaction loop of the game revolves around **spellcasting**:

- Spells are cast by the player and instantiated as `ASpellBase`-derived
  actors in the world.
- Once cast, spells interact with the environment through **physics
  collisions**: on impact/activation, they can apply a **radial force
  impulse** to nearby physics-simulated objects and/or trigger destruction
  on Chaos-enabled geometry.
- The crafting interaction (selecting Runes, assembling a spell) happens
  through the `WBP_SpellMenu` widget, which reads valid combinations from
  the `FCraftingRecipe` data table before allowing a spell to be crafted
  and equipped/cast.

---

## Physics Systems

No custom physics simulation was developed for this project. All physics
and destruction behavior relies on **Unreal Engine's built-in Chaos
system**:

- **Chaos Destruction** is used to make level geometry fracturable, so that
  cast spells can visibly break apart and displace parts of the
  environment.
- **Chaos Physics** (rigid body simulation) is used for how objects react
  to spell impacts, primarily through **radial force** applied on
  collision, rather than any bespoke force/impulse code.

This choice kept physics behavior robust and consistent with engine
defaults, at the cost of fine-grained custom control over destruction or
force behavior.

---

## Main Technical Choices

- **Hybrid C++/Blueprint workflow**: core data structures and reusable logic
  (e.g. `FCraftingRecipe`, `ASpellBase`) were implemented in C++ for
  performance and structure, while UI and iteration-heavy gameplay logic
  (e.g. `WBP_SpellMenu`) were built in Blueprint for faster iteration.
- **Data-driven spellcrafting**: using a `UDataTable`-based approach
  (`FCraftingRecipe`) allows spell recipes to be defined and tuned as data
  rather than hardcoded logic, making it easier to add/balance new spells.
- **Reliance on Unreal's Chaos system** rather than custom physics, to
  achieve reliable destruction and force effects within the project's time
  constraints.
- **Significant hard-coding across the project**, primarily due to time
  constraints during development. This was a conscious trade-off to reach a
  working, playable state rather than a fully generalized/data-driven
  system throughout.

---

## AI Statement of Intent

During the development of this project, I used **Claude** (Anthropic) as an
AI assistant throughout multiple stages of the design and implementation
process. This section details how and why it was used, in line with the
requirement that any AI-assisted work remain understood, verified, tested,
and explainable by me.

### Tools Used

- **Claude** (Anthropic) — used as a conversational AI assistant for both
  design discussions and code-related help throughout the project.

### Where AI Was Used

Claude was used across two main areas of the project:

1. **Design and scoping**: discussing the feasibility of gameplay ideas
   (notably around the Spellcraft system) within the available time frame,
   and helping shape the project's scope and guide document.
2. **Code implementation and debugging**: assisting with C++ and Blueprint
   code, particularly around the crafting system (`FCraftingRecipe`,
   `ASpellBase`) and troubleshooting issues encountered during development.

### Why It Was Used

As this project was built under real time constraints, and involved
learning **Unreal C++** during development, Claude was used to:

- Validate whether certain gameplay ideas were realistically achievable
  given the time available, before committing development time to them.
- Get unstuck faster when encountering bugs or unfamiliar Unreal Engine
  APIs/patterns.
- Get explanations of Unreal Engine and C++ concepts that were new to me,
  effectively supporting the learning process alongside implementation.

### How It Was Used

- **Brainstorming and feasibility discussions**: talking through spell
  system ideas and mechanics, and discussing which were realistic to
  implement given the project's timeframe, to help define the project's
  guide document and overall scope.
- **Code assistance**: asking Claude to help write or fix specific pieces
  of C++/Blueprint logic, and explain *why* a given solution worked, rather
  than using code without understanding it.
- **Q&A / explanations**: asking direct questions about Unreal Engine
  systems (e.g. Data Tables, Chaos, C++/Blueprint interoperability) to
  build up my own understanding of the engine.

All AI-suggested code and design ideas were reviewed, tested in-editor, and
adjusted by me before being integrated into the project — nothing was used
without being understood first.

### Benefits Obtained

- **Better project scoping**: helped define a more realistic and achievable
  project scope given the time constraints, reducing the risk of
  over-scoping the Spellcraft system.
- **Faster problem-solving**: sped up debugging and reduced time lost on
  blockers, especially around unfamiliar C++/Unreal-specific issues.
- **Learning acceleration**: contributed meaningfully to learning Unreal
  Engine's C++ workflow, which I had limited prior experience with, by
  pairing explanations with hands-on implementation help.

### Limitations Encountered

- **Hallucinated functions/APIs**: on several occasions, Claude referenced
  Unreal Engine functions or APIs that do not actually exist, requiring
  manual verification against Unreal's documentation/source and correction
  before the code would compile or work correctly.
- Because of this, all AI-suggested code required **manual verification,
  testing, and in some cases rewriting**, reinforcing the need to treat AI
  output as a starting point rather than a final answer.
