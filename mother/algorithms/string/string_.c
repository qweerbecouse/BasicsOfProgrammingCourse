#include "string_.h"

__attribute__((unused))size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

__attribute__((unused))char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

__attribute__((unused))char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

__attribute__((unused))char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

__attribute__((unused))char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (isspace(*rbegin) && rbegin != rend) {
        rbegin--;
    }

    return rbegin;
}

__attribute__((unused))char *findSpaceReverse(char *rbegin, const char *rend) {
    while (!isspace(*rbegin) && rbegin != rend) {
        rbegin--;
    }

    return rbegin;
}

__attribute__((unused))int strcmp_(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

__attribute__((unused))char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    beginDestination += endSource - beginSource;

    return beginDestination;
}

__attribute__((unused))char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination;
}

__attribute__((unused))char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }

        rbeginSource--;
    }

    return beginDestination;
}

__attribute__((unused))void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}