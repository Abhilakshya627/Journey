document.addEventListener('DOMContentLoaded', () => {
    // Smooth scrolling for navigation links
    const navLinks = document.querySelectorAll('nav a');
    navLinks.forEach(link => {
        link.addEventListener('click', (e) => {
            e.preventDefault();
            const targetId = e.target.getAttribute('href').substring(1);
            const targetSection = document.getElementById(targetId);
            window.scrollTo({
                top: targetSection.offsetTop,
                behavior: 'smooth'
            });
        });
    });

    // Toggle dark mode
    const toggleDarkMode = document.createElement('button');
    toggleDarkMode.textContent = 'Toggle Dark Mode';
    toggleDarkMode.style.position = 'fixed';
    toggleDarkMode.style.bottom = '20px';
    toggleDarkMode.style.right = '20px';
    toggleDarkMode.style.padding = '10px 20px';
    toggleDarkMode.style.backgroundColor = '#0078d7';
    toggleDarkMode.style.color = 'white';
    toggleDarkMode.style.border = 'none';
    toggleDarkMode.style.borderRadius = '5px';
    toggleDarkMode.style.cursor = 'pointer';
    document.body.appendChild(toggleDarkMode);

    // Check for saved user preference for dark mode
    if (localStorage.getItem('darkMode') === 'true') {
        document.body.classList.add('dark-mode');
    }

    toggleDarkMode.addEventListener('click', () => {
        document.body.classList.toggle('dark-mode');
        localStorage.setItem('darkMode', document.body.classList.contains('dark-mode'));
    });

    // Handle contact form submission (placeholder)
    const contactForm = document.getElementById('contact-form');
    contactForm.addEventListener('submit', (e) => {
        e.preventDefault();
        alert('Thank you for your message! I will get back to you soon.');
        contactForm.reset(); // Reset the form after submission
    });
});