# 🧬 Bio-Medcpp

**Bio-Medcpp** is a lightweight Python package designed for biomedical text processing. It provides tools for segmenting clinical narratives, extracting named entities, and mapping those entities to standardized ICD codes — all with a focus on speed and modularity.

---

## 🚀 Features

### 1. `sentence_sectionizer`
Breaks down biomedical or clinical text into structured sections and sentences.

- Identifies common clinical sections
- Supports custom section headers
- Returns clean sentence-level segmentation for downstream NLP tasks

### 2. `ner` (Named Entity Recognition)
Extracts biomedical entities from unstructured text.

- Recognizes diseases, symptoms, procedures, medications, and anatomical terms
- Built-in support for domain-specific vocabularies
- Outputs entity spans, types, and confidence scores
- Edit context and target rules

### 3. `entity_icd` Code Mapping
Maps extracted entities to standardized **ICD-10** codes.

- Supports both ICD 9 and ICD 10
- Attaches ICD codes to entity
- Returns ICD codes with metadata


