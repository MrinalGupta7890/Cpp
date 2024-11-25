#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>

// Module 1: Media Library Management

struct Track {
    int trackID;
    std::string title;
    std::string artist;
    int duration;  // in seconds
};

class MediaLibrary {
private:
    std::vector<Track> tracks;
    std::map<std::string, std::vector<Track>> artistMap;

public:
    void addTrack(const Track& track) {
        tracks.push_back(track);
        artistMap[track.artist].push_back(track);
    }

    void createPlaylist(std::list<Track>& playlist, const std::vector<int>& trackIDs) {
        for (int id : trackIDs) {
            auto it = std::find_if(tracks.begin(), tracks.end(),
                                   [id](const Track& t) { return t.trackID == id; });
            if (it != tracks.end()) {
                playlist.push_back(*it);
            }
        }
    }

    void searchByArtist(const std::string& artist) {
        if (artistMap.find(artist) != artistMap.end()) {
            std::cout << "Tracks by " << artist << ":\n";
            for (const Track& t : artistMap[artist]) {
                std::cout << t.title << " (" << t.duration / 60 << ":" << t.duration % 60 << ")\n";
            }
        } else {
            std::cout << "No tracks found for artist: " << artist << "\n";
        }
    }

    int calculatePlaylistDuration(const std::list<Track>& playlist) {
        int totalDuration = 0;
        for (const Track& track : playlist) {
            totalDuration += track.duration;
        }
        return totalDuration;
    }

    void displayTracks() {
        std::cout << "Media Library:\n";
        for (const Track& t : tracks) {
            std::cout << t.trackID << ". " << t.title << " by " << t.artist
                      << " (" << t.duration / 60 << ":" << t.duration % 60 << ")\n";
        }
    }
};

// Module 2: Navigation Favorites

struct Location {
    double latitude;
    double longitude;
    std::string description;
};

class NavigationFavorites {
private:
    std::map<std::string, Location> favorites;

public:
    void addFavoriteLocation(const std::string& name, const Location& location) {
        favorites[name] = location;
    }

    void retrieveLocation(const std::string& name) {
        if (favorites.find(name) != favorites.end()) {
            const Location& loc = favorites[name];
            std::cout << "Location: " << name << "\n"
                      << "Latitude: " << loc.latitude << ", Longitude: " << loc.longitude << "\n"
                      << "Description: " << loc.description << "\n";
        } else {
            std::cout << "Location not found.\n";
        }
    }

    void deleteFavoriteLocation(const std::string& name) {
        if (favorites.erase(name)) {
            std::cout << "Location '" << name << "' deleted.\n";
        } else {
            std::cout << "Location not found.\n";
        }
    }

    void updateLocationDescription(const std::string& name, const std::string& newDescription) {
        if (favorites.find(name) != favorites.end()) {
            favorites[name].description = newDescription;
            std::cout << "Description for " << name << " updated.\n";
        } else {
            std::cout << "Location not found.\n";
        }
    }

    void displayFavorites() {
        std::cout << "Favorite Locations:\n";
        for (const auto& pair : favorites) {
            const Location& loc = pair.second;
            std::cout << pair.first << ": " << loc.latitude << ", " << loc.longitude
                      << " - " << loc.description << "\n";
        }
    }
};

// Module 3: User Profile Management

struct UserProfile {
    int userID;
    std::string userName;
    int preferredVolume;
    std::list<int> favoriteStations;
};

class UserProfileManager {
private:
    std::vector<UserProfile> profiles;
    std::map<int, UserProfile*> profileMap;

public:
    void addUserProfile(const UserProfile& profile) {
        profiles.push_back(profile);
        profileMap[profile.userID] = &profiles.back();
    }

    void modifyUserPreferences(int userID, int volume, const std::list<int>& favoriteStations) {
        if (profileMap.find(userID) != profileMap.end()) {
            UserProfile* profile = profileMap[userID];
            profile->preferredVolume = volume;
            profile->favoriteStations = favoriteStations;
            std::cout << "User preferences updated.\n";
        } else {
            std::cout << "User profile not found.\n";
        }
    }

    void switchProfile(int userID) {
        if (profileMap.find(userID) != profileMap.end()) {
            UserProfile* profile = profileMap[userID];
            std::cout << "Switched to profile: " << profile->userName << "\n"
                      << "Preferred Volume: " << profile->preferredVolume << "\n"
                      << "Favorite Stations: ";
            for (int station : profile->favoriteStations) {
                std::cout << station << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "User profile not found.\n";
        }
    }

    void displayProfiles() {
        std::cout << "User Profiles:\n";
        for (const UserProfile& profile : profiles) {
            std::cout << profile.userID << ": " << profile.userName
                      << " (Volume: " << profile.preferredVolume << ")\n";
        }
    }
};

int main() {
    // Test Media Library Module
    MediaLibrary mediaLibrary;
    mediaLibrary.addTrack({1, "Song A", "Artist 1", 180});
    mediaLibrary.addTrack({2, "Song B", "Artist 1", 210});
    mediaLibrary.addTrack({3, "Song C", "Artist 2", 240});

    mediaLibrary.displayTracks();

    std::list<Track> playlist;
    mediaLibrary.createPlaylist(playlist, {1, 2});
    std::cout << "Total Playlist Duration: " << mediaLibrary.calculatePlaylistDuration(playlist) / 60 << " minutes.\n";

    mediaLibrary.searchByArtist("Artist 1");

    // Test Navigation Favorites Module
    NavigationFavorites navFavorites;
    navFavorites.addFavoriteLocation("Beach", {34.0522, -118.2437, "Beautiful beach"});
    navFavorites.addFavoriteLocation("Park", {40.7128, -74.0060, "City park"});

    navFavorites.retrieveLocation("Beach");
    navFavorites.updateLocationDescription("Beach", "Sandy beach with a great view.");
    navFavorites.deleteFavoriteLocation("Park");

    // Test User Profile Management Module
    UserProfileManager userManager;
    userManager.addUserProfile({1, "Alice", 50, {101, 102}});
    userManager.addUserProfile({2, "Bob", 70, {103, 104}});

    userManager.switchProfile(1);
    userManager.modifyUserPreferences(2, 80, {105, 106});
    userManager.switchProfile(2);

    return 0;
}
