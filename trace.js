// trace.js

const log = (...arg) => console.log(...arg)
const curriedLog = area => filename => (...message) => log(area, filename, ...message)

const logInfo = curriedLog("[info]"); // log("[info]", filename, ...message)
const logDebug = curriedLog("[debug]");
const logError = curriedLog("[error]");

const localLogInfo = logInfo("trace.js"); // log("[info]", "trace.js", ...message)
const localLogDebug = logDebug("trace.js");
const localLogError = logError("trace.js");

const test = (...args) => {
    localLogInfo(...args)
    localLogDebug(...args)
    localLogError(...args)
}
test("hello", "world")

