"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", { value: true });
var tasks_vision_0_10_2_1 = require("https://cdn.jsdelivr.net/npm/@mediapipe/tasks-vision@0.10.2");
var demosSection = document.getElementById("demos");
var objectDetector;
var runningMode = "IMAGE";
// Initialize the object detector
var initializeObjectDetector = function () { return __awaiter(void 0, void 0, void 0, function () {
    var vision;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0: return [4 /*yield*/, tasks_vision_0_10_2_1.FilesetResolver.forVisionTasks("https://cdn.jsdelivr.net/npm/@mediapipe/tasks-vision@0.10.2/wasm")];
            case 1:
                vision = _a.sent();
                return [4 /*yield*/, tasks_vision_0_10_2_1.ObjectDetector.createFromOptions(vision, {
                        baseOptions: {
                            modelAssetPath: "https://storage.googleapis.com/mediapipe-models/object_detector/efficientdet_lite0/float16/1/efficientdet_lite0.tflite",
                            delegate: "GPU"
                        },
                        scoreThreshold: 0.5,
                        runningMode: runningMode
                    })];
            case 2:
                objectDetector = _a.sent();
                demosSection.classList.remove("invisible");
                return [2 /*return*/];
        }
    });
}); };
initializeObjectDetector();
/********************************************************************
 // Demo 1: Grab a bunch of images from the page and detection them
 // upon click.
 ********************************************************************/
var imageContainers = document.getElementsByClassName("detectOnClick");
for (var _i = 0, imageContainers_1 = imageContainers; _i < imageContainers_1.length; _i++) {
    var imageContainer = imageContainers_1[_i];
    imageContainer.children[0].addEventListener("click", handleClick);
}
/**
 * Detect objects in still images on click
 */
function handleClick(event) {
    return __awaiter(this, void 0, void 0, function () {
        var highlighters, infos, ratio, detections;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    highlighters = event.target.parentNode.getElementsByClassName("highlighter");
                    while (highlighters[0]) {
                        highlighters[0].parentNode.removeChild(highlighters[0]);
                    }
                    infos = event.target.parentNode.getElementsByClassName("info");
                    while (infos[0]) {
                        infos[0].parentNode.removeChild(infos[0]);
                    }
                    if (!objectDetector) {
                        alert("Object Detector is still loading. Please try again.");
                        return [2 /*return*/];
                    }
                    if (!(runningMode === "VIDEO")) return [3 /*break*/, 2];
                    runningMode = "IMAGE";
                    return [4 /*yield*/, objectDetector.setOptions({ runningMode: "IMAGE" })];
                case 1:
                    _a.sent();
                    _a.label = 2;
                case 2:
                    ratio = event.target.height / event.target.naturalHeight;
                    detections = objectDetector.detect(event.target);
                    displayImageDetections(detections, event.target);
                    return [2 /*return*/];
            }
        });
    });
}
function displayImageDetections(result, resultElement) {
    var ratio = resultElement.height / resultElement.naturalHeight;
    console.log(ratio);
    for (var _i = 0, _a = result.detections; _i < _a.length; _i++) {
        var detection = _a[_i];
        // Description text
        var p = document.createElement("p");
        p.setAttribute("class", "info");
        p.innerText =
            detection.categories[0].categoryName +
                " - with " +
                Math.round(parseFloat(detection.categories[0].score) * 100) +
                "% confidence.";
        // Positioned at the top left of the bounding box.
        // Height is whatever the text takes up.
        // Width subtracts text padding in CSS so fits perfectly.
        p.style =
            "left: " +
                detection.boundingBox.originX * ratio +
                "px;" +
                "top: " +
                detection.boundingBox.originY * ratio +
                "px; " +
                "width: " +
                (detection.boundingBox.width * ratio - 10) +
                "px;";
        var highlighter = document.createElement("div");
        highlighter.setAttribute("class", "highlighter");
        highlighter.style =
            "left: " +
                detection.boundingBox.originX * ratio +
                "px;" +
                "top: " +
                detection.boundingBox.originY * ratio +
                "px;" +
                "width: " +
                detection.boundingBox.width * ratio +
                "px;" +
                "height: " +
                detection.boundingBox.height * ratio +
                "px;";
        resultElement.parentNode.appendChild(highlighter);
        resultElement.parentNode.appendChild(p);
    }
}
/********************************************************************
 // Demo 2: Continuously grab image from webcam stream and detect it.
 ********************************************************************/
var video = document.getElementById("webcam");
var liveView = document.getElementById("liveView");
var enableWebcamButton;
// Check if webcam access is supported.
function hasGetUserMedia() {
    return !!(navigator.mediaDevices && navigator.mediaDevices.getUserMedia);
}
// Keep a reference of all the child elements we create
// so we can remove them easilly on each render.
var children = [];
// If webcam supported, add event listener to button for when user
// wants to activate it.
if (hasGetUserMedia()) {
    enableWebcamButton = document.getElementById("webcamButton");
    enableWebcamButton.addEventListener("click", enableCam);
}
else {
    console.warn("getUserMedia() is not supported by your browser");
}
// Enable the live webcam view and start detection.
function enableCam(event) {
    return __awaiter(this, void 0, void 0, function () {
        var constraints;
        return __generator(this, function (_a) {
            if (!objectDetector) {
                console.log("Wait! objectDetector not loaded yet.");
                return [2 /*return*/];
            }
            // Hide the button.
            enableWebcamButton.classList.add("removed");
            constraints = {
                video: true
            };
            // Activate the webcam stream.
            navigator.mediaDevices
                .getUserMedia(constraints)
                .then(function (stream) {
                video.srcObject = stream;
                video.addEventListener("loadeddata", predictWebcam);
            })
                .catch(function (err) {
                console.error(err);
                /* handle the error */
            });
            return [2 /*return*/];
        });
    });
}
var lastVideoTime = -1;
function predictWebcam() {
    return __awaiter(this, void 0, void 0, function () {
        var startTimeMs, detections;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    if (!(runningMode === "IMAGE")) return [3 /*break*/, 2];
                    runningMode = "VIDEO";
                    return [4 /*yield*/, objectDetector.setOptions({ runningMode: "VIDEO" })];
                case 1:
                    _a.sent();
                    _a.label = 2;
                case 2:
                    startTimeMs = performance.now();
                    // Detect objects using detectForVideo.
                    if (video.currentTime !== lastVideoTime) {
                        lastVideoTime = video.currentTime;
                        detections = objectDetector.detectForVideo(video, startTimeMs);
                        displayVideoDetections(detections);
                    }
                    // Call this function again to keep predicting when the browser is ready.
                    window.requestAnimationFrame(predictWebcam);
                    return [2 /*return*/];
            }
        });
    });
}
function displayVideoDetections(result) {
    // Remove any highlighting from previous frame.
    for (var _i = 0, children_1 = children; _i < children_1.length; _i++) {
        var child = children_1[_i];
        liveView.removeChild(child);
    }
    children.splice(0);
    // Iterate through predictions and draw them to the live view
    for (var _a = 0, _b = result.detections; _a < _b.length; _a++) {
        var detection = _b[_a];
        var p = document.createElement("p");
        p.innerText =
            detection.categories[0].categoryName +
                " - with " +
                Math.round(parseFloat(detection.categories[0].score) * 100) +
                "% confidence.";
        p.style =
            "left: " +
                (video.offsetWidth -
                    detection.boundingBox.width -
                    detection.boundingBox.originX) +
                "px;" +
                "top: " +
                detection.boundingBox.originY +
                "px; " +
                "width: " +
                (detection.boundingBox.width - 10) +
                "px;";
        var highlighter = document.createElement("div");
        highlighter.setAttribute("class", "highlighter");
        highlighter.style =
            "left: " +
                (video.offsetWidth -
                    detection.boundingBox.width -
                    detection.boundingBox.originX) +
                "px;" +
                "top: " +
                detection.boundingBox.originY +
                "px;" +
                "width: " +
                (detection.boundingBox.width - 10) +
                "px;" +
                "height: " +
                detection.boundingBox.height +
                "px;";
        liveView.appendChild(highlighter);
        liveView.appendChild(p);
        // Store drawn objects in memory so they are queued to delete at next call.
        children.push(highlighter);
        children.push(p);
    }
}
